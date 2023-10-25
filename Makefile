SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
EXESRC=$(wildcard exesrc/*c)
EXEOBJ=$(patsubst %c, %o, $(EXESRC))
INC=inc/
CFLAGS=-I $(INC) 

EXE=$(EXESRC:%.c=%)

.SECONDARY:

all: $(EXE)

$(EXE): %: %.o
	gcc $< $(CFLAGS) -o $@ -lm
	mv $@ exe/

%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

run: all
	for binary in exe/*; do \
	echo "Running $$binary..."; \
        ./$$binary; \
    done

clean:
	rm -rf $(OBJ) $(EXEOBJ) $(OBJ) exe/*