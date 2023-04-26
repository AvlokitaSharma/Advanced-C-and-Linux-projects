g++ -pthread mySort.h mySort.cpp -c
g++ -pthread mySort.o -o mySort
g++ verifySort.cpp -o verifySort
