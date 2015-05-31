MIDFILE = acline.o share.o fstring.o toponode.o getData.o bus.o
SHELL = cmd.exe

getData:$(MIDFILE)
	g++ -Wall $(MIDFILE) 

bus.o:bus.cpp
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

.PHONY: clean
clean:
	rm $(MIDFILE)