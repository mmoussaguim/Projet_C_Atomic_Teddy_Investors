CFLAGS = -Wall -Wextra -std=c99 -c  -ggdb

OBJ= project-0.o good.o stockex.o queue.o 
OBJTEST=test-0.o queue.o good.o stockex.o

all: project 

project : $(OBJ)
	gcc -o project $(OBJ) -lm 


good.o: src/good.c src/good.h src/define.h
	gcc $(CFLAGS)   src/good.c

project-0.o: src/project-0.c  src/queue.h src/stockex.h src/good.h  src/teddy.h src/define.h
	gcc $(CFLAGS)   src/project-0.c

queue.o: src/queue.c src/queue.h src/stockex.h src/good.h src/teddy.h 
	gcc $(CFLAGS)   src/queue.c

stockex.o: src/stockex.c src/stockex.h src/good.h 
	gcc $(CFLAGS)   src/stockex.c


test: $(OBJTEST)
	gcc $(OBJTEST) -o test  -lm  && ./test



test-0.o: tst/test-0.c src/queue.h src/stockex.h src/good.h  src/teddy.h
	gcc $(CFLAGS) tst/test-0.c -o test-0.o

clean:
	rm -f test-0.o stockex.o good.o queue.o project-0.o project test
