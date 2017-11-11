test:
	gcc -o testres testres.c libresistance.so -Wl,-rpath,.

lib:
	gcc -c -fPIC libresistance.c
	gcc -shared -fPIC -o libresistance.so libresistance.o
