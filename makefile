COMPILER   = g++
LINKER     = g++
LINK       =    -lm 
OPTIONS    = -O3 -std=c++11  -march=native
LIBS =   
INCLUDE = 
EXEC = WolfCpp

OBJS = main.o model.o tools.o config.o

.cpp.o:
	$(COMPILER) $(OPTIONS) $(INCLUDE) -c $< 
all: $(OBJS)
	$(LINKER) -o $(EXEC) $(OBJS) $(LINK)
clean:
	rm -f *.o


