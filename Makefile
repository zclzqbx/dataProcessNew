VPATH = ../src
MIDFILE = bus.o acline.o share.o fstring.o toponode.o getData.o 

getData:$(MIDFILE)
	g++ -o getData $(MIDFILE)

bus.o:bus.cpp bus.h
	g++ -Wall -c bus.cpp
	
acline.o:acline.cpp
	g++ -Wall -c acline.cpp
	
toponode.o:toponode.cpp
	g++ -Wall -c toponode.cpp
	
fstring.o:fstring.cpp
	g++ -Wall -c fstring.cpp
	
share.o:share.cpp
	g++ -Wall -c share.cpp
	
getData.o:getData.cpp
	g++ -Wall -c getData.cpp
	
clean:
	rm $(MIDFILE)
