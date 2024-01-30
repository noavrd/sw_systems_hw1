.PHONEY : all clean loops recursives loopd recursived# לא קובץ
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


main.o : main.c NunClass.h
	gcc -c main.c -o main.o

basicClassification.o : basicClassification.c NunClass.h
	gcc -c basicClassification.c -o basicClassification.o

advancedClassificationRecursion.o : advancedClassificationRecursion.c NunClass.h
	gcc -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

advancedClassificationLoop.o : advancedClassificationLoop.c NunClass.h
	gcc -c advancedClassificationLoop.c -o advancedClassificationLoop.o

# static #

libclassloops.a : advancedClassificationLoop.o basicClassification.o
	ar -rc libclassloops.a advancedClassificationLoop.o basicClassification.o

libclassrec.a : advancedClassificationRecursion.o basicClassification.o
	ar -rc libclassrec.a advancedClassificationRecursion.o basicClassification.o

mains : main.o libclassrec.a
	gcc -o mains main.o -L. libclassrec.a

#dyn#

basicClassificationDYN.o : basicClassification.c NunClass.h
	gcc -c -fpic basicClassification.c -o basicClassificationDYN.o

advancedClassificationRecursionDYN.o : advancedClassificationRecursion.c NunClass.h
	gcc -c -fpic advancedClassificationRecursion.c -o advancedClassificationRecursionDYN.o

advancedClassificationLoopDYN.o : advancedClassificationLoop.c NunClass.h
	gcc -c -fpic advancedClassificationLoop.c -o advancedClassificationLoopDYN.o

libclassrec.so : advancedClassificationRecursionDYN.o basicClassificationDYN.o
	gcc advancedClassificationRecursionDYN.o basicClassificationDYN.o -shared -o libclassrec.so
	export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

libclassloops.so : advancedClassificationLoopDYN.o basicClassificationDYN.o
	gcc advancedClassificationLoopDYN.o basicClassificationDYN.o -shared -o libclassloops.so
	export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

maindloop : main.o libclassloops.so
	gcc -o maindloop main.o -L. ./libclassloops.so

maindrec : main.o libclassrec.so
	gcc -o maindrec main.o -L. ./libclassrec.so



