#!/bin/bash
Target="Hw1"
compiler="g++"
warning="-Wall -Wextra -std=c++14"
OBJ="main.o command.o initialize.o register.o create_user.o check_user.o"
rm -f $OBJ $Target
echo "Comiling...It's normal to show warning since I do the linking after all comiling"
$compiler $warning -c main.cpp main.o
$compiler $warning -c command.cpp command.o
$compiler $warning -c operation/dataoperation/initialize.cpp initialize.o
$compiler $warning -c operation/dataoperation/create_user.cpp create_user.o
$compiler $warning -c operation/dataoperation/check_user.cpp check_user.o
$compiler $warning -c operation/register.cpp register.o
$compiler $warning $OBJ -L/operation/dataoperation/sqlite/sqlite3.lib -lsqlite3 -o $Target
echo "Finish"
rm -f $OBJ