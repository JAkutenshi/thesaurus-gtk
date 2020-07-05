compile: main.c
	gcc `pkg-config --cflags gtk+-3.0` -o thesaurus-gtk main.c `pkg-config --libs gtk+-3.0`

all: compile

clean:
	rm thesaurus-gtk
