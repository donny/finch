#if HAVE_CONFIG_H
# include <config.h>
#endif

#include "finchcommon.h"

#include <stdio.h>

void print_color(void * data)
{
  printf("Hello from %s!\n", (const char *)data);
}
