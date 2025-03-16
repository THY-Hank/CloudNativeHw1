#!/bin/bash
Target="Hw1_r13922141_cli_app"
build_dir="r13922141_cli_app/build"
mkdir -p "$build_dir"
compiler="g++"
warning="-Wall -Wextra -std=c++14"
m_src="r13922141_cli_app"
op_src="r13922141_cli_app/operation"
data_src="r13922141_cli_app/operation/dataoperation"
main=""
for file in "$m_src"/*.cpp; do
    main+="$build_dir/$(basename "${file%.cpp}.o") "
done
operation=""
for file in "$op_src"/*.cpp; do
    operation+="$build_dir/$(basename "${file%.cpp}.o") "
done
data=""
for file in "$data_src"/*.cpp; do
    data+="$build_dir/$(basename "${file%.cpp}.o") "
done
OBJ="$main$operation$data"
rm -f $OBJ $Target
echo "Comiling..."
for file in "$m_src"/*.cpp; do
    $compiler $warning -c "$file" -o "$build_dir/$(basename "${file%.cpp}.o")"
done

for file in "$op_src"/*.cpp; do
    $compiler $warning -c "$file" -o "$build_dir/$(basename "${file%.cpp}.o")"
done
for file in "$data_src"/*.cpp; do
    $compiler $warning -c "$file" -o "$build_dir/$(basename "${file%.cpp}.o")"
done
$compiler $warning $OBJ -L/operation/dataoperation/sqlite/sqlite3.lib -lsqlite3 -o $Target
echo "Finish"
rm -f $OBJ