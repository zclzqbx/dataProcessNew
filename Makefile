MIDFILE = dataClass.o share.o fstring.o getData.o

getData:$(MIDFILE)
	g++ -Wall -o getData -g $(MIDFILE)
dataClass.o:dataClass.cpp
	g++ -Wall -g -c dataClass.cpp
share.o:share.cpp
	g++ -Wall -g -c share.cpp
fstring.o:fstring.cpp
	g++ -Wall -g -c fstring.cpp
getData.o:getData.cpp
	g++ -Wall -g -c getData.cpp

.PHONY: clean

clean:
	rm $(MIDFILE)
