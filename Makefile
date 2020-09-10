CC=gcc
DEPS = libraries.h dependencies.h globalconstants.h helpers.h prompt.h loop.h history.h pwd.h echo.h cd.h ls.h commands.h
OBJ = main.c helpers.c prompt_helpers.c loop.c history.c pwd.c echo.c cd.c ls.c

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

dash: $(OBJ)
		gcc -g -o $@ $^ $(CFLAGS)
