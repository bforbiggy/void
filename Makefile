default:
	gcc void.c util.c -o void -Wall -Wextra -lm

run: default
	./void

clean:
	rm void