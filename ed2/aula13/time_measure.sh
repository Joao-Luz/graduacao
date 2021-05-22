#!/bin/bash
mkdir -p output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
NC='\033[0m'
OUTFILE="./output/table.csv"
echo "input;few_uniq_10M_sorted;few_uniq_10M_unif_rand;nearly_sorted_100k;nearly_sorted_1m;nearly_sorted_10m;reverse_sorted_100k;reverse_sorted_1m;reverse_sorted_10m;sorted_100k;sorted_1m;sorted_10m;unif_rand_100k;unif_rand_1m;unif_rand_10m" > $OUTFILE

mkdir -p bin

for filename in "$2"/*; do
    program=$(basename -- $filename)
    program="${program%.*}"
    gcc -w -O3 main.c $filename -o ./bin/$program
    echo -n "${program}" >> "$OUTFILE"
    echo -e "Running ${LIGHTBLUE}${program}${NC}..."
    while IFS=';' read -r input n; do
        if [ -e "./input/${input}" ]
        then
            echo -n -e "  ${GREEN}${input}${NC} with ${YELLOW}n=${n}${NC}... "

            output=$(timeout 20s ./bin/${program} ${n} false < input/${input})
            if [ "$output" == "" ]
            then
                echo -n ";timeout" >> "$OUTFILE"
                echo -e "[ ${RED}timeout${NC} ] "
            else
                IFS=':' read -r param t <<< "$output";
                nt=${t:1:-1}
                echo -n ";${nt}" >> "$OUTFILE"
                echo -e "[ ${LIGHTBLUE}${nt}s${NC} ] "
            fi

        else
            echo -e "${RED}ERROR:${NC} no file named ${input} in your input folder! Exiting..." && exit 0
        fi
    done < "$1"
    echo "" >> "$OUTFILE"
done