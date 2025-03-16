#!/bin/bash
Target="Hw1"
compiler="g++"
warning="-Wall -Wextra -std=c++14"
OBJ="main.o command.o initialize.o register.o creating_list.o create_user.o check_user.o create_item.o get_new_id.o"
rm -f $OBJ $Target
echo "Comiling...It's normal to show warning since I do the linking after all comiling"
$compiler $warning -c main.cpp main.o
$compiler $warning -c command.cpp command.o
$compiler $warning -c operation/dataoperation/initialize.cpp initialize.o
$compiler $warning -c operation/dataoperation/create_user.cpp create_user.o
$compiler $warning -c operation/dataoperation/check_user.cpp check_user.o
$compiler $warning -c operation/dataoperation/get_new_id.cpp get_new_id.o
$compiler $warning -c operation/dataoperation/create_item.cpp create_item.o
$compiler $warning -c operation/register.cpp register.o
$compiler $warning -c operation/creating_list.cpp creating_list.o
$compiler $warning $OBJ -L/operation/dataoperation/sqlite/sqlite3.lib -lsqlite3 -o $Target
echo "Finish"
rm -f $OBJ