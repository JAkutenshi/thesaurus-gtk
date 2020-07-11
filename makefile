compile: main.c
	gcc `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o thesaurus-gtk main.c

all: compile

clean:
	rm thesaurus-gtk
