GCCPARAMS = -Iinclude -g

OBJECTS=obj/main.o \
	obj/board.o \

obj/%.o: src/%.c
	mkdir -p $(@D)
	gcc $(GCCPARAMS) -c -o $@ $<

all: chess_engine

chess_engine: $(OBJECTS)
	gcc $(OBJECTS) -o chess_engine $(GCCPARAMS)

clean:
	rm -rf chess_engine obj
