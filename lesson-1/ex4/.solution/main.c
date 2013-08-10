#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

int			main(int ac, char **av)
{
  if (ac < 3)
    return EXIT_SUCCESS;

  char *st1 = av[1];
  char *st2 = av[2];
  unsigned int res = 0;

  int i = 0;
  while (st2[i])
    {
      int j = 0;
      while (st1[j])
	{
	  if (st1[j] == st2[i])
	    {
	      ++res;
	      break;
	    }
	  ++j;
	}
      ++i;
    }

  if (res == strlen(st2))
    printf("oui\n");
  else
    printf("non\n");
  return EXIT_SUCCESS;
}
