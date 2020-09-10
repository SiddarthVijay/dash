# dash
*dead again shell*
---

## Product Overview
This is a rudimentary working implementation of a shell for Unix based systems, written completely in C

## Features
### `echo`
- Prints a message to the terminal
- It supports multiple arguments as well
```
$ echo Hello World!
Hello World!
```

### `ls`
- Lists all the files/directories/links in a given source path
- Supports the usage of `.`, `..`, and `~`
- Has two flags,
    - `-a`: does not ignore entries starting with .
    - `-l`: long listing format
```
$ ls ~
Makefile
README.md
cd.c
cd.h
commands.h
dash
dependencies.h
echo.c
echo.h
globalconstants.h
helpers.c
helpers.h
history.c
history.h
libraries.h
loop.c
loop.h
ls.c
ls.h
main.c
prompt.h
prompt_helpers.c
pwd.c
pwd.h

$ ls -l ..
-rwx r-x r-x  1  siddarth  siddarth    44872  Sep 10 23:31  dash 

$ ls -la ..
drwx r-x r-x  3  siddarth  siddarth     4096  Sep 10 23:32  . 
drwx r-x r-x  6  siddarth  siddarth     4096  Sep 10 23:32  .. 
-rwx r-x r-x  1  siddarth  siddarth    44872  Sep 10 23:31  dash 
```

### `pwd`
- Prints the present working directory
```
$ pwd
/home/siddarth/Workspace/C/dash
```

### history
- Prints the tracked history of the commands executed on the shell
- Has one flag,
    - `-n`: returns only `n` entries
```
$ history
$ echo Hello World!
ls ~
ls -l ..
ls -a ..
ls -la ..
pwd
history

$history -n 3
ls -la ..
pwd
history
``` 

### `cd`
- Command to change directory
- Supports the usage of `.`, `..`, and `~`
```
$ pwd
/home/siddarth/Workspace/C
$ cd ..
$ pwd
/home/siddarth/Workspace
$ cd ~
$ pwd
/home/siddarth/Workspace/C/dash
```

## Installation
```
git clone https://github.com/SiddarthVijay/dash.git
cd dash
make
```

## Getting Started
```
./dash
```