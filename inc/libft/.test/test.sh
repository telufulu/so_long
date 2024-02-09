#!/bin/zsh
#gcc -Wall -Werror -Wextra -fsanitize=address -g3 main.c srcs/part1.c srcs/part2.c -I ../ -L .. -lft

# Descomentar si hay bonus
make re bonus -C ../
gcc -Wall -Werror -Wextra main.c srcs/part1.c srcs/part2.c srcs/bonus.c -I test.h -I ../ -L .. -lft

#make re -C ../ 
#gcc -Wall -Werror -Wextra main.c srcs/part1.c srcs/part2.c -I test.h -I ../ -L .. -lft
./a.out $1
