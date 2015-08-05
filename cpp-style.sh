#!/bin/bash

for file in $@
do
    formatted_file=`mktemp`
    clang-format-3.6 $file > $formatted_file
    diff --minimal --side-by-side -W 170 $file $formatted_file | cat -v > $file.diff
    rm $formatted_file
done
