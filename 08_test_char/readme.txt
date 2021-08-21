# run like this
#for gcc make
make clean
make
#./build_gcc/test08
make run

#for cmake + make case
#cd ./build
##cmake -G "Unix Makefiles" ..
##cmake .
##set in CMakeList.tx or set here, one times is enough
#cmake -DCMAKE_BUILD_TYPE=Debug .
##cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .
##cmake -DCMAKE_BUILD_TYPE=Release .
#make
#./Test08_Hello
