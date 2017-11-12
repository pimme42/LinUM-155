set -v
gcc -o electrotest electrotest.c -L. -Llibcomponent -Llibresistance -Llibpower -lpower -lcomponent -lresistance -Wl,-rpath,lib/
