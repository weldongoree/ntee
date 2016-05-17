ntw: ntw.c ntee.h
	gcc -o ntw ntw.c

ntee: ntee.c ntee.h
	gcc -o ntee ntee.c

clean:
	rm ntee ntw

