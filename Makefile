MIDFILE = bus.o share.o fstring.o acline.o\
          toponode.o getData.o unit.o

getData:$(MIDFILE)
	g++ -Wall -o getData -g $(MIDFILE)
bus.o:bus.cpp
	g++ -Wall -g -c bus.cpp
share.o:share.cpp
	g++ -Wall -g -c share.cpp
fstring.o:fstring.cpp
	g++ -Wall -g -c fstring.cpp
acline.o:acline.cpp
	g++ -Wall -g -c acline.cpp
toponode.o:toponode.cpp
	g++ -Wall -g -c toponode.cpp
getData.o:getData.cpp
	g++ -Wall -g -c getData.cpp

.PHONY: clean

clean:
	rm $(MIDFILE)
