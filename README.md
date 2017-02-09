# finch

Finch is a simple CLI calculator using a small ANSI color printing library built using [Autoconf](https://www.gnu.org/software/autoconf/autoconf.html), [Automake](https://www.gnu.org/software/automake/), and [Libtool](https://www.gnu.org/software/libtool/).

### Background

This project is part of [52projects](https://donny.github.io/52projects/) and the new stuff that I learn through this project: [Autoconf](https://www.gnu.org/software/autoconf/autoconf.html) (revisit), [Automake](https://www.gnu.org/software/automake/) (revisit), and [Libtool](https://www.gnu.org/software/libtool/).

Autoconf, Automake, and Libtool are parts of the [GNU Build System](https://en.wikipedia.org/wiki/GNU_Build_System). I [used](https://github.com/donny/c-template) them in the past around six years ago. I was thinking to revisit and relearn these tools; and hopefully use them in future projects.

### GNU Build System

According to Wikipedia, the [GNU Build System](https://en.wikipedia.org/wiki/GNU_Build_System), also known as the Autotools, is a suite of programming tools designed to assist in making source code packages portable to many Unix-like systems. They are the tools that make it possible for a user to download a library or program, and run:

```shell
$ ./configure
$ make
$ make install
```

The Autotools were designed to create portable configuration scripts and makefiles that work correctly on a user's system whether it's Linux, macOS, or BSD system. Most developers understand the purpose of a build tool such as `make` but what's the purpose of `configure`? Although we have standards such as [POSIX](https://en.wikipedia.org/wiki/POSIX), sometimes operating systems behave differently because of the underlying implementation and APIs. The purpose of `configure` is to find out these differences and set the appropriate flags or `#define` so that the code that makes use of these `#define` can work correctly.

A minimal `Makefile.am` is shown below followed by an [asciinema](https://asciinema.org) recording that shows how to use the build tools.

```
AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = main
main_SOURCES = main.c
```

[![asciicast](https://asciinema.org/a/8tsea18bfgq5j93iiazcn5a82.png)](https://asciinema.org/a/8tsea18bfgq5j93iiazcn5a82)

Notes:

1. We use `AUTOMAKE_OPTIONS = foreign` so that we don't need to generate unnecessary files as required by the GNU coding standards (e.g. `NEWS` or `AUTHORS`).
2. We run `autoscan` to produce `configure.scan`.
3. We need to edit `configure.scan` and add the line `AM_INIT_AUTOMAKE` to initialise Automake. Yes, it's annoying and we should not have to.
4. We run `autoreconf -vi` (verbose and copy missing auxiliary files) to generate the `configure` script. The `autoreconf` program executes the configuration tools in the Autoconf and Automake packages as required by each project.
5. We run `./configure` to generate the actual `Makefile`.
6. We run `make` to build the source code.
7. The *pipeline* looks something like:

```
[file Makefile.am] -> autoscan -> [file configure.scan] -> edit -> [file configure.ac] -> autoreconf -> [file configure] -> ./configure -> [file Makefile] -> make
```

### Project

...

### Implementation

The project is composed of three main parts:

- A `convenience library` which is a static library that's only used within the containing project for printing [ANSI color codes](http://pueblo.sourceforge.net/doc/manual/ansi_color_codes.html), in [`common`](https://github.com/donny/finch/blob/master/common).
- A public shared library built using the static convenience library in [`libfinch`](https://github.com/donny/finch/blob/master/libfinch) with the public header file in [`include`](https://github.com/donny/finch/blob/master/include).
- A calculator program that is built using [Flex](https://en.wikipedia.org/wiki/Flex_(lexical_analyser_generator)) and [Bison](https://en.wikipedia.org/wiki/GNU_bison) code from the book [flex & bison](http://shop.oreilly.com/product/9780596155988.do) by John Levine in [`src`](https://github.com/donny/finch/blob/master/src).

The main [`configure.ac`](https://github.com/donny/finch/blob/master/configure.ac):

```autoconf
AC_PREREQ([2.69])
AC_INIT([finch], [0.1], [info@example.com])
AM_INIT_AUTOMAKE
LT_PREREQ([2.4])
LT_INIT([dlopen])

AC_CONFIG_SRCDIR([src/parser.y])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LEX
AC_PROG_YACC
# AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 common/Makefile
                 include/Makefile
                 libfinch/Makefile
                 src/Makefile])
AC_OUTPUT
```

The main [`Makefile.am`](https://github.com/donny/finch/blob/master/Makefile.am):

```make
AUTOMAKE_OPTIONS = foreign
SUBDIRS = common include libfinch src
```

### Conclusion

...
