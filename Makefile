MIDFILE = bus.o share.o fstring.o acline.o toponode.o getData.o

getData:$(MIDFILE)
	g++ -Wall -o getData $(MIDFILE)
bus.o:bus.cpp

share.o:share.cpp

fstring.o:fstring.cpp

acline.o:acline.cpp

toponode.o:toponode.cpp

getData.o:getData.cpp

.PHONY: clean

clean:
	rm $(MIDFILE)
