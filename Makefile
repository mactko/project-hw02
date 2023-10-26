SRC=$(wildcard src/*c) #nalaze se svi source fileovi -> efektivno library fileovi
OBJ=$(patsubst %c, %o, $(SRC)) #obj fileovi library fileova
EXESRC=$(wildcard exesrc/*c) #nalaze se svi .c fileovi s main funkcijom (runable) 
EXEOBJ=$(patsubst %c, %o, $(EXESRC))
INC=inc/ 
CFLAGS=-I $(INC) 

EXE=$(patsubst %.c, % , $(EXESRC))

.SECONDARY:

all: $(EXE)

$(EXE): $(EXEOBJ) $(OBJ)
	gcc $< $(CFLAGS) -o $@ -lm
	mv $@ exe/

$(OBJ): $(SRC)
	gcc -c $< $(CLFAGS) -o $@

$(EXEOBJ): $(EXESRC)
	gcc -c $< $(CFLAGS) -o $@

run: all
	for exeFile in exe/*; do \
	echo "Running $$exeFile..."; \
        ./$$exeFile; \
    done

clean:
	rm -rf $(OBJ) $(EXEOBJ) $(OBJ) $(EXE) exe/*