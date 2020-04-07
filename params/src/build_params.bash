#!/bin/bash
clang++ -std=c++11  -w -DSANFUNC -DMOBIUS_LITTLE_ENDIAN -DMOBIUS_LINUX -O3    -Wno-deprecated -m64 -MMD -D MOBIUSROOT=\"/home/giulio/git/mobius/edu.illinois.mobius.cpp/\" -I../.. -I/home/giulio/git/mobius/edu.illinois.mobius.cpp//Cpp/external/include -I../../external/include -I/home/giulio/git/mobius/edu.illinois.mobius.cpp/  -c params.cpp -o OBJECTS/u1604-m64/params.o

ar rvs ../../lib/u1604-m64/libparams.a OBJECTS/u1604-m64/params.o
