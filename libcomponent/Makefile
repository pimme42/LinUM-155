all: pro

pro: lib
	mkdir -p ./lib
	gcc -o pro main.c -L./lib -lpower -lresistance -lcomponent -Wl,-rpath,./lib

install: lib
	sudo rm -fr /usr/bin/linUM
	sudo rm -f /usr/bin/pro
	sudo rm -fr /usr/lib/lib
	sudo cp -arvf lib /usr/lib 
	sudo cp -arvf ./../linUM /usr/bin
	rm -rf /usr/bin/linUM/lib
	gcc -o pro /usr/bin/linUM/main.c -L/usr/lib/lib -lpower -lresistance -lcomponent -Wl,-rpath,/usr/lib/lib
	sudo cp -avf pro /usr/bin

lib:	
	gcc -c -fPIC e_resistance.c
	gcc -c -fPIC power.c
	gcc -c -fPIC calc_resistance.c
	gcc -shared -fPIC -o libcomponent.so e_resistance.o
	gcc -shared -fPIC -o libpower.so power.o
	gcc -shared -fPIC -o libresistance.so calc_resistance.o
	mkdir -p ./lib
	mv *.so ./lib

clear: 
	sudo rm -fr /usr/bin/linUM
	sudo rm -f /usr/bin/pro
	sudo rm -fr /usr/lib/lib
	rm -fr lib
	rm -f pro
	rm -f *.o
	rm -f *.so 
