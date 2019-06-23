cd src
g++ -c md5.cpp -o md5.o
g++ -c main.cpp
g++ main.o md5.o -o test
rm -f main.o
rm -f md5.o
./test
rm -r test
cd ..