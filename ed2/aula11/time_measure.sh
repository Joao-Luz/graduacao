#!/bin/bash
mkdir -p output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
NC='\033[0m'
OUTFILE="./output/table.csv"
echo "input;nearly_sorted_100k;nearly_sorted_1m;reverse_sorted_100k;reverse_sorted_1m;sorted_100k;sorted_1m;unif_rand_100k;unif_rand_1m" > $OUTFILE

mkdir -p bin

for program in "merge_sort" "cutoff" "skip" "skip_cutoff" "bottomup" "bottomup_cutoff" "bottomup_skip"; do
    gcc main.c $program.c -o ./bin/$program
    echo -n "${program}" >> "$OUTFILE"
    echo -e "Running ${LIGHTBLUE}${program}${NC}..."
    while IFS=';' read -r input n; do
        if [ -e "./input/${input}" ]
        then
            echo -e "  ${GREEN}${input}${NC} with ${YELLOW}n=${n}${NC}..."

            output=$(./bin/${program} ${n} false < input/${input})

            IFS=':' read -r param t <<< "$output";
            nt=${t:1:-1}
            echo -n ";${nt}" >> "$OUTFILE"
        else
            echo -e "${RED}ERROR:${NC} no file named ${input} in your input folder! Exiting..." && exit 0
        fi
    done < "$1"
    echo "" >> "$OUTFILE"
done