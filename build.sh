#!/bin/bash

if [[ -z ${BDMSYS} ]]; then
  echo "Please source ROOT first"
  exit 1
fi

set -x -e
rm -rf reproducer-dict* libreproducer.so

genreflex src/reproducer.h -o reproducer-dict.cc -s selection.xml -Isrc -DUSE_DICT
g++ -fPIC -c reproducer-dict.cc -o reproducer-dict.o `root-config --cflags --ldflags --libs` -DUSE_DICT
g++ -shared src/reproducer.h -o libreproducer.so reproducer-dict.o -fPIC `root-config --cflags --ldflags --libs`
