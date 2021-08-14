# run like this
#cmake -G "Unix Makefiles" ..
cmake ..
make clean
make
echo "please makesure the lib is in ../lib path"
./Test05_Hello
