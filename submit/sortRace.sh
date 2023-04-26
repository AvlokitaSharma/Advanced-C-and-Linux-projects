#!/bin/bash

shuf -r -i 100000-999999 -n 1000000 > numbers.txt
time sort numbers.txt >sysSort.out
time ./mySort numbers.txt mySort.out
 ./verifySort  mySort.out
