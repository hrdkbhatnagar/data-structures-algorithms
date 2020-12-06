compRecMS: driver.o merge.o msortRecursive.o 
	gcc driver.o msortRecursive.o merge.o -o testRecursive
	
compIterMS:  driver.o merge.o msortIter.o
	gcc driver.o msortIter.o merge.o -o testIterative 

runRecMS: compRecMS
	./testRecursive

runIterMS: compIterMS
	./testIterative

comparer.o : comparer.c
	gcc -c comparer.c

compare : comparer.o merge.o msortRecursive.o msortIter.o
	gcc comparer.o msortRecursive.o msortIter.o merge.o -o testCompare

driver.o : driver.c
	gcc -c driver.c

mergeRec.o : msortRecursive.c merge.h
	gcc -c msortRecursive.c

mergeIter.o : msortIter.c merge.h
	gcc -c msortIter.c

merge.o : merge.c
	gcc -c merge.c

