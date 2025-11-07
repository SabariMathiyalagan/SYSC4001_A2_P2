#!/bin/bash
set -e
mkdir -p bin && rm -f bin/*
g++ -std=c++17 -O0 -g -o bin/parent parent_101296691_101296257.cpp
g++ -std=c++17 -O0 -g -o bin/child  child_101296691_101296257.cpp


echo "Run:   ./bin/parent"
