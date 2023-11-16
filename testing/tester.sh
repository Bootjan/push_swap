#!/bin/bash

# cc counter.c -o counter -L./libft -lftprintf
# cc randints.c -o randints && ./randints > randints.txt
# python3 randints.py > randints.txt
randints=$(cat test_cases)
echo "$randints"
# ./push_swap $randints > output.txt
# count=$(./counter $output)
# echo "$count"

N=0
cat test_cases | while read LINE ; do
    N=$((N+1))
    ../push_swap $LINE >> output.txt
done
# for i in `seq 1 $numLines`; do
#         line=$(sed -n '{$i}p' randints.txt)
#         ./push_swap $line >> output.txt
# done