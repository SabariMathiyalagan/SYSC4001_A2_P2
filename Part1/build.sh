#!/bin/bash
# Bare-bones build: place executable in ./bin/main

if [ ! -d "bin" ]; then
  mkdir bin
else
  rm -f bin/*
fi

g++ -std=c++17 -O0 -g -o bin/main main_101296691_101296257.cpp


echo "Run:   ./bin/main"
echo "Kill:  pkill -f main   (or: ps -ef | egrep './bin/main' ; kill <PID_parent> <PID_child>)"
