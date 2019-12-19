#!/bin/bash
set -x
set -e
rm -rf main-dict* main libmain.so

# rootcling main-dict.cc -c classes.h Linkdef.h
genreflex src/*.h -o main-dict.cc -s selection.xml -Isrc -DUSE_DICT
g++ -fPIC -c main-dict.cc -o main-dict.o `root-config --cflags --ldflags --libs` -I/src -DUSE_DICT

g++ -shared -DUSE_DICT -o libmain.so main.cc main-dict.o -fPIC `root-config --cflags --ldflags --libs` -Isrc
g++ -DUSE_DICT main.cc -o main main-dict.o `root-config --cflags --libs` libmain.so
