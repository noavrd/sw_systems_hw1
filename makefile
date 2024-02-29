.PHONY : all clean loops recursives loopd recursived

loops : libclassloops.a
recursives : libclassrec.a
recursived : libclassrec.so
loopd : libclassloops.so

all: loops recursives loopd recursived mains maindloop maindrec

clean : 
	rm *.o
	rm *.a
	rm *.so
	rm mains maindloop maindrec


main.o : main.c NumClass.h
	gcc -wall -g -c main.c -o main.o

basicClassification.o : basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c -o basicClassification.o

advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -fPIC -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

advancedClassificationLoop.o : advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -fPIC -c advancedClassificationLoop.c -o advancedClassificationLoop.o


# static #

libclassloops.a : advancedClassificationLoop.o basicClassification.o
	ar -rc libclassloops.a advancedClassificationLoop.o basicClassification.o

libclassrec.a : advancedClassificationRecursion.o basicClassification.o
	ar -rc libclassrec.a advancedClassificationRecursion.o basicClassification.o

mains : main.o libclassrec.a
	gcc  -wall -o mains main.o libclassrec.a -lm

#dyn#

basicClassificationDYN.o : basicClassification.c NumClass.h
	gcc -c -fpic basicClassification.c -o basicClassificationDYN.o

advancedClassificationRecursionDYN.o : advancedClassificationRecursion.c NumClass.h
	gcc -c -fpic advancedClassificationRecursion.c -o advancedClassificationRecursionDYN.o

advancedClassificationLoopDYN.o : advancedClassificationLoop.c NumClass.h
	gcc -c -fpic advancedClassificationLoop.c -o advancedClassificationLoopDYN.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -fPIC -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared -fPIC -o libclassloops.so basicClassification.o advancedClassificationLoop.o

maindloop : main.o libclassloops.so
	gcc -wall -g -o maindloop main.o ./libclassloops.so -lm

maindrec : main.o libclassrec.so
	gcc -wall -g -o maindrec main.o ./libclassrec.so -lm



