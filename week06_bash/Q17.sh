#!/bin/bash

file_wordcnt() {

    files=$(ls *.txt 2>/dev/null)

    for file in $files
    do
        result=$(wc -w < "$file")
        echo "$file 파일의 단어는 $result개 입니다."
    done
}

file_wordcnt
