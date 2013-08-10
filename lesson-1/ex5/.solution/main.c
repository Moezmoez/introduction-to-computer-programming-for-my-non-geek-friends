#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

int			main(int ac, char **av)
{
  if (ac < 4)
    return EXIT_SUCCESS;

  int w = atoi(av[1]);
  int h = atoi(av[2]);
  int v = atoi(av[3]);

  int **tab;

  tab = malloc(sizeof(int*) * h);

  int it = 0;
  while (it < h)
    {
      tab[it] = malloc(sizeof(int) * w);
      int jt = 1;
      tab[it][0] = v - it;
      while (jt < w)
	{
	  tab[it][jt] = tab[it][jt - 1] + 1;
	  ++jt;
	}
      ++it;
    }

  int res[w];
  
  it = 0;
  while(it < w)
    {
      res[it++] = 0;
    }

  it = 0;
  while (it < h)
    {
      int jt = 0;
      while (jt < w)
	{
	  printf("%i ", tab[it][jt]);
	  res[jt] += tab[it][jt];
	  ++jt;
	}
      printf("\n");
      ++it;
    }
  printf("\n");
  it = 0;
  while (it < w)
    printf("%i ", res[it++]);
  printf("\n");

  it = 0;
  while (it < h)
    {
      free(tab[it]);
      ++it;
    }

  free(tab);

  return EXIT_SUCCESS;
}
