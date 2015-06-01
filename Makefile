MIDFILE = bus/bus.o share/share.o fstring/fstring.o acline/acline.o toponode/toponode.o getData.o

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
