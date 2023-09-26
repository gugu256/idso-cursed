# idso-cursed

A CURSED deadfish compiler

## Usage

You'll need these installed on your local machine :
 - gcc
 - make

First, download the `compiler.c` and `Makefile` files contained in this repo and put them in a directory on your local machine, then using build it using make:

`$ make`

Once it's done, you can use the compiler's executable to compile a deadfish program :

`$ idso-cursed a-df-program myprogram.df` The first argument is the name you want the executable to have, the second is source file

And voila, you got yourself a binary executable out of your deadfish program that you can run like this :

`$ ./a-df-program`

[more info about the deadfish programming language](https://esolangs.org/wiki/Deadfish)