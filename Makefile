CC=gcc
DEPS = libraries.h dependencies.h globalconstants.h helpers.h prompt.h loop.h
OBJ = main.c helpers.c prompt_helpers.c loop.c

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

dash: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
