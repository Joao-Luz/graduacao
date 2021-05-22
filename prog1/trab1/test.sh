#!/bin/bash
mkdir -p output
ghc --make main.hs &>/dev/null
rm *.o *.hi
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
NC='\033[0m'


while IFS=',' read -r input p s; do
    if [ -e "${input}" ]
    then
        echo -e -n "Running ${LIGHTBLUE}${input}${NC} with ${YELLOW}test percentage = ${p}${NC} and ${YELLOW}random seed = ${s}${NC}... "

        name=$(basename -- "$input")
        name="${name%.*}"
        outfile="output/conf-$name-$p-$s.txt"
        ./main > "output/$name-$p-$s.txt" << EOF
$input
$outfile
$p
$s
EOF
        echo -e "[ ${GREEN}OK!${NC} ]"
    else
        echo -e "${RED}ERROR:${NC} no file named ${input} in your input folder! Exiting..." && exit 0
    fi
done < "$1"
