all: createThreads parallel1 parallel2 parallel3

createThreads: createThreads.c
	gcc -pthread -o createThreads createThreads.c

parallel1: parallel1.c
	gcc -pthread -o parallel1 parallel1.c

parallel2: parallel2.c
	gcc -pthread -o parallel2 parallel2.c

parallel3: parallel3.c
	gcc -pthread -o parallel3 parallel3.c

clean:
	rm -f createThreads parallel1 parallel2 parallel3