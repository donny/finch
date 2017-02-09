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

void print_color(color c, char *msg)
{
  switch(c) {
    case RED:
      printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, msg);
      break;
    case GREEN:
      printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, msg);
      break;
    case YELLOW:
      printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, msg);
      break;
    case BLUE:
      printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET, msg);
      break;
    case MAGENTA:
      printf(ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET, msg);
      break;
    case CYAN:
      printf(ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, msg);
      break;
    case WHITE:
      printf(ANSI_COLOR_WHITE "%s" ANSI_COLOR_RESET, msg);
      break;
    default:
      printf("%s", msg);
      break;
  }
}
