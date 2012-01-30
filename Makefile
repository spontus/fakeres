
all:
	mkdir bin
	gcc -fPIC -c -Wall src/lib.c -o bin/libfakeres.o
	gcc -shared bin/libfakeres.o -ldl -o bin/libfakeres.so
	cp src/fakeres bin/fakeres
	chmod +x bin/fakeres
	
clean: uninstall
	rm -rf bin 

install:
	cp bin/libfakeres.so /usr/lib
	cp bin/fakeres /usr/bin
	chmod +x /usr/bin/fakeres

uninstall: 
	rm -f /usr/lib/libfakeres.so
	rm -f /usr/bin/fakeres 

