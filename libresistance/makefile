test:
	gcc -o testres testres.c libresistance.so -Wl,-rpath,.

lib:
	gcc -c -fPIC calc_resistance.c
	gcc -shared -fPIC -o libresistance.so calc_resistance.o
