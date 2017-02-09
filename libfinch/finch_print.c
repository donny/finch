#include <libfinch.h>
#include <finchcommon.h>
#include <stdio.h>

void finch_print_color(color c, char *msg)
{
  switch(c) {
    case RED:
      print_color(F_RED, msg);
      break;
    case GREEN:
      print_color(F_GREEN, msg);
      break;
    case YELLOW:
      print_color(F_YELLOW, msg);
      break;
    case BLUE:
      print_color(F_BLUE, msg);
      break;
    case MAGENTA:
      print_color(F_MAGENTA, msg);
      break;
    case CYAN:
      print_color(F_CYAN, msg);
      break;
    case WHITE:
      print_color(F_WHITE, msg);
      break;
    default:
      printf("%s", msg);
      break;
  }
}
