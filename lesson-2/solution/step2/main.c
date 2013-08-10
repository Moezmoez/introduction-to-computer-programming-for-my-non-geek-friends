#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

void			initImg(unsigned short ***img, int w, int h)
{
  *img = malloc(sizeof(unsigned short*) * h);

  unsigned short it = 0;
  while (it < h)
    {
      (*img)[it] = malloc(sizeof(unsigned short) * w * 3);
      unsigned short jt = 0;
      while (jt < w * 3)
	{
	  (*img)[it][jt] = 0;
	  ++jt;
	}
      ++it;
    }
}

void			drawLines(unsigned short **img, int w, int h)
{
  unsigned short it = 0;
  int revert = 0;

  while (it < h)
    {
      if (it % 40 == 0)
	{
	  revert = revert > 0 ? 0 : 1;
	}
      unsigned short jt = 0;
      while (jt < w * 3)
	{
	  if (revert == 1)
	    img[it][jt] = 0;
	  else if (revert == 0)
	    img[it][jt] = 255;
	  ++jt;
	}
      ++it;
    }  
}


void			freeImg(unsigned short **img, int h)
{
  int it;
  it = 0;
  while (it < h)
    {
      free(img[it]);
      ++it;
    }
  free(img);
}

void			registerImage(unsigned short **img, int w, int h, char *filename)
{
  FILE			*file;

  file = fopen(filename, "w");
  if (!file)
    {
      printf("Cannot open file %s\n", filename);
      exit(EXIT_SUCCESS);
    }

  fprintf(file, "%i %i\n", w, h);

  int y = 0;
  while (y < h)
    {
      int x = 0;
      while (x < w * 3)
	{
	  fprintf(file, "%i,%i,%i ", img[y][x], img[y][x + 1], img[y][x + 2]);
	  x += 3;
	}
      fprintf(file, "\n");
      ++y;
    }
  fclose(file);
}

int			main(int ac, char **av)
{
  if (ac < 3)
    return EXIT_SUCCESS;

  int w = atoi(av[1]);
  int h = atoi(av[2]);
  unsigned short **img = NULL;

  initImg(&img, w, h);
  drawLines(img, w, h);
  registerImage(img, w, h, "lines.jmc");
  freeImg(img, h);
  return EXIT_SUCCESS;
}
