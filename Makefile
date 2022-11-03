default:
	gcc void.c util.c xbgi/libXbgi.a -o void -Wall -Wextra -lm -lX11 -lm

run: default
	./void

clean:
	rm void xbgi/*.o