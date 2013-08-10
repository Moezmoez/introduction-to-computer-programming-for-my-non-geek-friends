#include		<cstdlib>
#include		<allegro5/allegro.h>
#include		<string>
#include		<sstream>
#include		<fstream>
#include		<iostream>
#include		<vector>

void			splitString(std::vector<std::string> & list, std::string & str)
{
  std::string		tmp;
  std::stringstream	s(str);

  list.clear();
  while(s >> tmp)
    list.push_back(tmp);
}

void			getColor(int &r, int &g, int &b, std::string &str)
{
  std::istringstream	ss(str);
  std::string		token;
  int			i = 0;

  while(std::getline(ss, token, ','))
    {
      if (i == 0)
	{
	  r = std::atoi(token.c_str());
	}
      else if (i == 1)
	{
	  g = std::atoi(token.c_str());
	}
      else
	{
	  b = std::atoi(token.c_str());
	}
      ++i;
    }
}

bool			parseFile(const std::string &filename, int &w, int &h)
{
  std::string           line;
  std::ifstream		myfile(filename.c_str());
  int			i = 0;
  int			x = 0;
  int			y = 0;

  if (myfile.is_open())
    {
      while (myfile.good())
        {
	  std::getline(myfile, line);

	  if (i == 0)
	    {
	      std::string tk1, tk2;
	      std::stringstream ss(line);

	      ss >> tk1;
	      ss >> tk2;

	      if (tk2.size() < 1)
		return false;
	      w = std::atoi(tk1.c_str());
	      h = std::atoi(tk2.c_str());
	      if (w <= 0 || h <= 0)
		return false;
	      if (!al_create_display(w, h))
		return false;
	    }

	  else
	    {
	      std::vector<std::string> list;
	      splitString(list, line);
	      std::vector<std::string>::iterator it = list.begin();
	      x = 0;
	      while (it != list.end())
		{
		  int r, g, b;
		  getColor(r, g, b, (*it));
		  al_put_pixel(x, y, al_map_rgb(r, g, b));
		  ++it;
		  ++x;
		}
	      ++y;
	    }
	  ++i;
        }
      myfile.close();
    }  
  return true;
}

int			main(int ac, char **av)
{
  if (ac < 2)
    return EXIT_SUCCESS;

  ALLEGRO_EVENT_QUEUE *event_queue;

  if (!al_init())
    return EXIT_FAILURE;
  if (!al_install_keyboard())
    return EXIT_FAILURE;
  event_queue = al_create_event_queue();
  if (!event_queue)
    return false;
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  bool run = true;

  int w = 0;
  int h = 0;

  std::cout << "Parsing your image file " << av[1] << " please wait..." << std::endl;
  if (!parseFile(av[1], w, h))
    {
      std::cerr << "Loading failed, your image file is invalid." << std::endl;
    }
  else
    {
      std::cout << "Parsing succeed !" << std::endl;
      al_flip_display();
      ALLEGRO_EVENT ev;
      while (run)
	{
	  al_wait_for_event(event_queue, &ev);
	  if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
	    run = false;
	}
    }
  al_destroy_event_queue(event_queue);
  al_uninstall_keyboard();
  al_destroy_display(al_get_current_display());
  al_uninstall_system();
}
