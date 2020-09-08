CC=gcc
DEPS = dependencies.h globalconstants.h prompt.h
OBJ = main.c prompt_helpers.c

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
