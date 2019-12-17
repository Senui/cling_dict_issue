#!/bin/bash
set -x
set -e
rm -rf main-dict* main libmain.so

# rootcling main-dict.cc -c classes.h Linkdef.h
genreflex classes.h -o main-dict.cc -s selection.xml
g++ -fPIC -c main-dict.cc -o main-dict.o `root-config --cflags --ldflags --libs`

g++ -shared -o libmain.so classes.h main-dict.o `root-config --cflags --ldflags --libs`
g++ -fPIC main.cc -o main main-dict.o `root-config --cflags --libs` libmain.so
