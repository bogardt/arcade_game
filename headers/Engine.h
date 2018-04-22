#ifndef			__M_ENGINE_H__
#define			__M_ENGINE_H__

# include		"mSFML.hpp"

class			Engine
{
  public:
    explicit	Engine();
    ~Engine();
	void		start();

  private:
	  IGui		*_gui;
};

#endif			/* !__M_ENGINE_H__ */