#!/bin/bash

clear
# cores
red='\033[0;31m'
green='\033[0;32m'
reset='\033[0m'

# programa a ser testado
programa="./push_swap"
checker='./checker_linux'

declare -A sequencias=(
	["2 números"]="2 5"
	["3 números"]="3 8 1"
	["5 números"]="5 9 2 6 7"
	["100 números"]="$(seq 100 | shuf | tr '\n' ' ')"
	["500 números"]="$(shuf -i 1-500 -n 500)"
	["Numeros com repetição"]="1 2 3 4 5 6 7 8 9 10 1"
)

for chave in "${!sequencias[@]}"; do
	descricao="${sequencias[$chave]}"
	checker="$($programa $descricao | $checker $descricao )"
	printf "\n"
	echo "Testando sequência de $chave:"
	echo "Verificação do Checker: $checker"
	saida_valgrind=$(valgrind --leak-check=full $programa $descricao 2>&1 >valgrind_check)
	# analisar a saída do valgrind para verificar se há vazamentos de memória
	if echo "$saida_valgrind" | grep -q "All heap blocks were freed -- no leaks are possible"; then
		resultado_valgrind="VALGRIND CHECK -> $green OK $reset"
	else
		resultado_valgrind="VALGRIND CHECK -> $red FAIL$reset"
	fi
	#executar o programa com a sequência atual sem valgrind
	$programa $descricao >count

	# contar o número de linhas na saída normal
	num_linhas="$(cat count | wc -l)"
	# exibir o resultado do teste com valgrind
	echo "Verificando vazamentos da sequência $chave "
	printf "$resultado_valgrind"
	echo ""

	# exibir o resultado do teste normal
	echo "Sequência: $chave "
	echo "Linhas de saída:$num_linhas"
	echo ""
	rm -rf count
done
