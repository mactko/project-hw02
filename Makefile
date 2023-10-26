SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC)) 
EXESRC=$(wildcard exesrc/*c)  
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
	gcc -c $< $(CFLAGS) -o $@

$(EXEOBJ): $(EXESRC)
	gcc -c $< $(CFLAGS) -o $@

run: all
	for exeFile in exe/*; do \
	echo "Running $$exeFile..."; \
        ./$$exeFile; \
    done

clean:
	rm -rf $(OBJ) $(EXEOBJ) $(OBJ) $(EXE) exe/*