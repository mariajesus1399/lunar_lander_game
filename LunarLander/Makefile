# C compiler
CC=gcc

# Files
BASEDIR=.
INCLDIR=$(BASEDIR)/incl
SRCDIR=$(BASEDIR)/src
BINDIR=$(BASEDIR)/bin

OUTFILE=LunarLander

# Compiler options and flags
CFLAGS= -std=c11 -g -I$(INCLDIR) -o$(BINDIR)/$(OUTFILE) -lm -lallegro -lallegro_main -lallegro_acodec -lallegro_audio -lallegro_image -lallegro_font -lallegro_ttf
LFLAGS=


#######################################
# Targets 
#######################################

all: clean build run clean

build:
	$(CC) $(SRCDIR)/*.c  main.c $(CFLAGS) $(LFLAGS) `pkg-config --cflags --libs allegro-5` 

clean:
	rm -rf $(BINDIR)/* 

run:
	$(BINDIR)/$(OUTFILE)

.PHONY: all clean














