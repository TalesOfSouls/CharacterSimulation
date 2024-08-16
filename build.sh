#!/bin/bash

clear
mkdir -p ../build/simulation

#-Wno-strict-aliasing

cp settings.cfg ../build/simulation/settings.cfg

g++ -Wall -O3 -std=c++11 -m64 \
    -Wno-unused-result \
    -march=native -mfpmath=sse -maes -msse4.2 -mavx -mavx2 -mavx512dq -mavx512f \
    -pthread \
    sim_cross.cpp \
    -lsqlite3 \
    -o ../build/simulation/sim_cross