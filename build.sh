#!/bin/bash
Target="Hw1"
compiler="g++"
warning="-Wall -Wextra -std=c++14"
OBJ="main.o command.o"
rm -f $OBJ $Target
echo "Comiling..."
$compiler $warning -c main.cpp main.o
$compiler $warning -c command.cpp command.o
$compiler $warning $OBJ -o $Target
echo "Finish"