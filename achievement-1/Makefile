CFLAGS = -Wall -Wextra -std=c99 -c  -ggdb

OBJ= project-1.o good.o stockex.o queue.o 
OBJTEST=test-1.o queue.o good.o stockex.o

all: project 

project : $(OBJ)
	gcc -o project $(OBJ) -lm 


good.o: src/good.c src/good.h 
	gcc $(CFLAGS)   src/good.c

project-1.o: src/project-1.c  src/queue.h src/stockex.h src/good.h src/teddy.h src/define.h
	gcc $(CFLAGS)   src/project-1.c

queue.o: src/queue.c src/queue.h src/stockex.h src/good.h src/teddy.h src/define.h
	gcc $(CFLAGS)   src/queue.c

stockex.o: src/stockex.c src/stockex.h src/good.h src/define.h
	gcc $(CFLAGS)   src/stockex.c


test: $(OBJTEST)
	gcc $(OBJTEST) -o test  -lm  && ./test



test-1.o: tst/test-1.c src/queue.h src/stockex.h src/good.h  src/teddy.h src/define.h
	gcc $(CFLAGS) tst/test-1.c -o test-1.o

clean:
	rm -f test-1.o stockex.o good.o queue.o project-1.o project test
