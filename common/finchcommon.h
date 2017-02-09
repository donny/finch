#ifndef FINCHCOMMON_H_INCLUDED
#define FINCHCOMMON_H_INCLUDED

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

void print_color(color c, char *msg);

#endif /* FINCHCOMMON_H_INCLUDED */
