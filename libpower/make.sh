gcc -Wall -pedantic -ansi -c -fPIC calc_power.c
gcc -Wall -pedantic -ansi  -shared -fPIC -o libpower.so calc_power.o
