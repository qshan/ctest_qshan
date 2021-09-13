#!/bin/bash

# run like this
#cmake -G "Unix Makefiles" ..
#cmake ..
##set in CMakeList.tx or set here, one times is enough
cmake -DCMAKE_BUILD_TYPE=Debug ..
#cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
#cmake -DCMAKE_BUILD_TYPE=Release ..
make clean
make
./Test08_Hello
