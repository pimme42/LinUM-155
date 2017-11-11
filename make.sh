gcc -o electrotest electrotest.c -L. -Llibcomponent -Llibpower -lpower -lcomponent -Wl,-rpath,lib/
