FLAGS = -Wall
CC = g++
CFLAGS = $(FLAGS)
LIBS =  -lglut -lGL -lGLU  -lm -lGLEW 
#QT =

kaeru: light.o worldObj.o
	$(CC) $(CFLAGS) -o $@ light.o worldObj.o $(LIBS)

#sample: qts.o
#	$(CC) $(CFLAGS) -o $@ qts.o $(QT)


clean:
	rm *.o