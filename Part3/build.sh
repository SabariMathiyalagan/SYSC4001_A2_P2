#!/bin/bash
set -e
mkdir -p bin && rm -f bin/*
g++ -std=c++17 -O0 -g -o bin/parent parent.cpp
g++ -std=c++17 -O0 -g -o bin/child  child.cpp


echo "Run:   ./bin/parent"
