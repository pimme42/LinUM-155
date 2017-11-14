all: electrotest

# Välj kompilator
CC = gcc

# Sökväg till biblioteken
LIBSSRC = -Llib

# Vilka bibliotek som behövs
LIBS = -lpower -lcomponent -lresistance

# Växlar till kompilatorn vid utveckling
#CFLAGS = -g -Wall -ansi

# Växlar till kompilatorn vid produktion
CFLAGS = -O

# Var programmet ska installeras
INSTDIR = /usr/bin
LIB_INSTDIR = /usr/lib

# Vad programfilen ska heta
TARGET = electrotest
TARGET_COMPONENT = libcomponent.so
TARGET_RESISTANCE = libresistance.so
TARGET_POWER = libpower.so

# Sökväg där biblioteken ska lagras
LIBPATH = lib

# Skapar programmet från objektfiler
electrotest: lib
	$(CC) $(CFLAGS) -c -o $(TARGET).o electrotest.c
	$(CC) $(CFLAGS) -o $(TARGET) electrotest.o $(LIBSSRC) $(LIBS) -Wl,-rpath,$(LIBPATH)

# Skapar enbart biblioteken
lib: libpower/libpower.o libresistance/libresistance.o libcomponent/libcomponent.o
	mkdir -p $(LIBPATH)
	$(CC) $(CFLAGS) -shared -o $(LIBPATH)/$(TARGET_RESISTANCE) libpower/libpower.o
	$(CC) $(CFLAGS) -shared -o $(LIBPATH)/$(TARGET_POWER) libresistance/libresistance.o
	$(CC) $(CFLAGS) -shared -o $(LIBPATH)/$(TARGET_COMPONENT) libcomponent/libcomponent.o

libpower/libpower.o:
	$(CC) $(CFLAGS) -fPIC -o libpower/libpower.o -c libpower/calc_power.c

libresistance/libresistance.o:
	$(CC) $(CFLAGS) -fPIC -o libresistance/libresistance.o -c libresistance/calc_resistance.c

libcomponent/libcomponent.o:
	$(CC) $(CFLAGS) -fPIC -g -o libcomponent/libcomponent.o -c libcomponent/e_resistance.c



# Tar bort alla objektfiler
clean:
	-rm -f electrotest
	-rm -rf $(LIBPATH)
	-rm -f *.o
	-rm -f libcomponent/*.o
	-rm -f libpower/*.o
	-rm -f libresistance/*.o

# Installerar programmet
install: electrotest
# Kolla om vi har root-behörighet
	@if [ "$$EUID" -ne 0 ]; \
		then \
		echo "Du måste ha root-behörighet"; \
		exit 1; \
	fi
# Om biblioteksinstallationskatalogen inte finns, skapar vi den
	@if [ ! -e $(LIB_INSTDIR) ]; \
		then \
		mkdir $(LIB_INSTDIR); \
	fi
# Om biblioteksinstallationssökvägen är en katalog kan vi installera programmet
	@if [ -d $(LIB_INSTDIR) ]; \
		then \
		cp $(LIBPATH)/$(TARGET_POWER) $(LIB_INSTDIR); \
		cp $(LIBPATH)/$(TARGET_COMPONENT) $(LIB_INSTDIR); \
		cp $(LIBPATH)/$(TARGET_RESISTANCE) $(LIB_INSTDIR); \
		chmod 0755 $(LIB_INSTDIR)/$(TARGET_RESISTANCE); \
		chmod 0755 $(LIB_INSTDIR)/$(TARGET_POWER); \
		chmod 0755 $(LIB_INSTDIR)/$(TARGET_COMPONENT); \
		echo "Library installed in $(LIB_INSTDIR)";\
	else \
		echo "Sorry, $(LIB_INSTDIR) is not a directory"; \
	fi
# Om installationskatalogen inte finns, skapar vi den
	@if [ ! -e $(INSTDIR) ]; \
		then \
		mkdir $(INSTDIR); \
	fi

# Om installationssökvägen är en katalog kan vi installera programmet
# Vi måste länka om programmet så att det använder rätt bibliotek
	@if [ -d $(INSTDIR) ]; \
		then \
		$(CC) $(CFLAGS) -o $(INSTDIR)/$(TARGET) electrotest.o $(LIBS) -Wl,-rpath,$(LIB_INSTDIR); \
		chmod 0755 $(INSTDIR)/$(TARGET); \
		echo "Program installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) is not a directory"; \
	fi


# Avinstallerar programmet
uninstall:
	-rm $(INSTDIR)/$(TARGET)
	-rm $(LIB_INSTDIR)/$(TARGET_COMPONENT)
	-rm $(LIB_INSTDIR)/$(TARGET_POWER)
	-rm $(LIB_INSTDIR)/$(TARGET_RESISTANCE)
