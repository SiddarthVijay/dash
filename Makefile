CC=gcc
DEPS = libraries.h dependencies.h globalconstants.h helpers.h prompt.h loop.h history.h
OBJ = main.c helpers.c prompt_helpers.c loop.c history.c

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

dash: $(OBJ)
		gcc -g -o $@ $^ $(CFLAGS)
