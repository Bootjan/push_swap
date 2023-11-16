#!/bin/bash

# cc randints.c -o randints && ./randints > randints.txt
python3 randints.py > randints.txt
randints=$(cat randints.txt)
echo "$randints"
./push_swap $randints | ./checker_linux $randints


# N=0
# cat randints.txt | while read LINE ; do
#     N=$((N+1))
# done