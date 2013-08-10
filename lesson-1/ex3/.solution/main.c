#include		<stdlib.h>
#include		<stdio.h>

int			main(int ac, char **av)
{
  if (ac < 4)
    return EXIT_SUCCESS;

  char			sign;
  int			n1;
  int			n2;

  sign = av[1][0];
  n1 = atoi(av[2]);
  n2 = atoi(av[3]);

  switch(sign)
    {
    case '+':
      printf("%i\n", n1 + n2);
      break;
    case '-':
      printf("%i\n", n1 - n2);
      break;
    case '/':
      printf("%i\n", n1 / n2);
      break;
    case '*':
      printf("%i\n", n1 * n2);
      break;

    }
  return EXIT_SUCCESS;
}
