#if HAVE_CONFIG_H
# include <config.h>
#endif

#include "finchcommon.h"

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_color(f_color c, char *msg)
{
  switch(c) {
    case F_RED:
      printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, msg);
      break;
    case F_GREEN:
      printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, msg);
      break;
    case F_YELLOW:
      printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, msg);
      break;
    case F_BLUE:
      printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET, msg);
      break;
    case F_MAGENTA:
      printf(ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET, msg);
      break;
    case F_CYAN:
      printf(ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, msg);
      break;
    case F_WHITE:
      printf(ANSI_COLOR_WHITE "%s" ANSI_COLOR_RESET, msg);
      break;
    default:
      printf("%s", msg);
      break;
  }
}
