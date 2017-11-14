set -v
gcc -Wall -pedantic -ansi -shared -fPIC -o libpower.so calc_power.c
gcc -Wall -pedantic -ansi -o testprog test.c -L. -lpower -Wl,-rpath,.
./testprog
rm testprog libpower.so
