#!/usr/bin/env

SRC_DIR='./src'
INC_DIR='./include'

TO_FMT="$(find "${SRC_DIR}" -name '*.cpp')"
TO_FMT="${TO_FMT} $(find "${INC_DIR}" -name '*.h')"

clang-format -i ${TO_FMT}
