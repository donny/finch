#ifndef FINCHCOMMON_H_INCLUDED
#define FINCHCOMMON_H_INCLUDED

typedef enum
{
  F_RED,
  F_GREEN,
  F_YELLOW,
  F_BLUE,
  F_MAGENTA,
  F_CYAN,
  F_WHITE
} f_color;

void print_color(f_color c, char *msg);

#endif /* FINCHCOMMON_H_INCLUDED */
