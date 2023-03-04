#!/bin/bash

clear

red='\033[0;31m'
green='\033[0;32m'
reset='\033[0m'


checker='./checker_linux'
programa="./push_swap"
SEQ100=$(shuf -i 1-100 -n 100)
SEQ500=$(shuf -i 1-500 -n 500)
SEQ3=$(shuf -i 1-3 -n 3)
SEQ5=$(shuf -i 1-5 -n 5)

declare -A sequencias=(
	["2 números"]="2 5"
	["3 números"]=$SEQ3
	["5 números"]=$SEQ5
	["100 números"]=$SEQ100
	["500 números"]=$SEQ500
	["Numeros repetidos"]="1 2 3 4 5 6 7 8 9 10 1" 


)

norminette ./src

for chave in "${!sequencias[@]}"; do
	descricao="${sequencias[$chave]}"

	valgrind --leak-check=full -s $programa $descricao  > "valgrind_check/$chave" 2>&1
	printf "__________________________________________________________\n"
	echo "Testando sequência de $chave ->"
	echo "Verificação do Checker: $($programa $descricao | $checker $descricao  2>&1)"
	
	if  cat "valgrind_check/$chave" | grep -q "All heap blocks were freed -- no leaks are possible" \
	&&  cat "valgrind_check/$chave" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" ; then
		resultado_valgrind="VALGRIND CHECK -> $green OK $reset";
	else
		resultado_valgrind="VALGRIND CHECK -> $red FAIL$reset";
	fi

	$programa $descricao 2>&1 > count
	num_linhas="$(cat count | wc -l)"
	
	printf "$resultado_valgrind"
	echo ""

	echo "Sequência: $chave "
	echo "Linhas de saída:$num_linhas"
	rm -rf count
done
