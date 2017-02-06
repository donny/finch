AM_CFLAGS = --pedantic -Wall
AM_YFLAGS = -d

bin_PROGRAMS = calc
calc_SOURCES = parser.y scanner.l
calc_CPPFLAGS = -I$(top_srcdir)/common
calc_LDADD = @LEXLIB@ ../common/libfinchcommon.a
