#!/bin/bash
Target="Hw1"
compiler="g++"
warning="-Wall -Wextra -std=c++14"
OBJ="main.o command.o creating_list.o"
rm -f $OBJ $Target
echo "Comiling...It's normal to show warning since I do the linking after all comiling"
$compiler $warning -c main.cpp main.o
$compiler $warning -c command.cpp command.o
$compiler $warning -c operation/creating_list.cpp creating_list.o
$compiler $warning $OBJ -o $Target
echo "Finish"
rm -f $OBJ