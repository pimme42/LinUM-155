gcc -c -fPIC libpower.c
gcc -shared -fPIC -o libpower.so libpower.o
gcc -o test test.c -L. -lpower -Wl,-rpath,.
