#!/bin/bash
gcc -Wall -Wextra -ggdb twice.c -o twice -lm
gcc -Wall -Wextra -ggdb gates.c -o gates -lm
./gates.exe 