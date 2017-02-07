#include <libfinch.h>
#include <finchcommon.h>
#include <stdio.h>

void * finch_print_color(void * data)
{
  printf("FINCH: ");
  print_color(data);
}
