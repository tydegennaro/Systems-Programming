# This Makefile DOES NOT create automatic dependencies
# So, you will need to update the dependencies manually
# or create an auto one instead.

CC=gcc
CFLAGS=-Wall -g -c
LFLAGS=-Wall -g

EXECA=multsum
EXECB=freqCount
EXECC=goldbach
EXECD=tokenizerTester

OBJSA=multsum.o
OBJSB=freqCount.o
OBSJC=goldbach.o
OBJSD=tokenizerTester.o tokenizer.o

all: $(EXECA) $(EXECB) $(EXECC) $(EXECD) 

#===================================
# Dependencies for the object files
#   DONE MANUALLY!
#===================================
multsum.o: multsum.c
freqCount.o: freqCount.c
goldbach.o: goldbach.c
tokenizerTester.o: tokenizerTester.c tokenizer.h
tokenizer.o: tokenizer.c tokenizer.h

#===================================

# Construction instructions
$(EXECA): $(OBJSA)
	$(CC) $(LFLAGS) -o $@ $(OBJSA)

$(EXECB): $(OBJSB)
	$(CC) $(LFLAGS) -o $@ $(OBJSB)

$(EXECC): $(OBJSC)
	$(CC) $(LFLAGS) -o $@ $(OBJSC)

$(EXECD): $(OBJSD)
	$(CC) $(LFLAGS) -o $@ $(OBJSD)

%.o: %.c
	$(CC) $(CFLAGS) $*.c

clean:
	@echo "Cleaning out directory"
	-rm *.o $(EXECA) $(EXECB) $(EXECC) $(EXECD) *~
