gcc -Wall -pedantic -ansi -c -fPIC libpower.c
gcc -Wall -pedantic -ansi  -shared -fPIC -o libpower.so libpower.o
