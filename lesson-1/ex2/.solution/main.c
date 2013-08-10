#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>

int			main()
{
  write(1, "Cesar\n", 6);
  printf("J'ai %i ans\n", 24);
  return EXIT_SUCCESS;
}
