ts: turtleshell.c
	gcc turtleshell.c -o ts

clean:
	rm *~

run: ts
	./ts
