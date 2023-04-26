
./generate 1000000 100000 999999

time ./sort numbers.txt > sysSort.out

./verifySort sysSort.out

time ./mySort numbers.txt > mySort.out

./verifySort mySort.out
