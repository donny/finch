#ifndef LIBFINCH_H_INCLUDED
#define LIBFINCH_H_INCLUDED

typedef enum
{
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
} color;

void finch_print_color(color c, char *msg);

#endif /* LIBFINCH_H_INCLUDED */
