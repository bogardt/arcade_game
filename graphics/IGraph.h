#ifndef __IGRAPH_HPP__
#define __IGRAPH_HPP__

#define WIN_X (1200)
#define WIN_Y (800)
#define WIN_NAME "Arcade !"
#define FRAME (50)

#include <string>
#include <vector>

namespace Arcade
{
  namespace Graphic
  {

    typedef enum Context {
      MENU = 0,
      GAME,
      QUIT
    } Context;

    typedef enum Keyboard {
      ESCAPE = 0,
      TOP_ARROW,
      BOT_ARROW,
      LEFT_ARROW,
      RIGHT_ARROW,
      KEY_2,
      KEY_3,
      KEY_4,
      KEY_5,
      KEY_8,
      KEY_9,
      ENTER,
      LAST_KEY
    } Keyboard;

    class IGraph
    {
    public:
      virtual ~IGraph(void){};

    public: /* init and destroy graph functions */
      virtual bool init(unsigned int const winX,
                        unsigned int const winY,
                        char const *const winName) = 0;
      virtual void end(void) = 0;

    public: /* Graphical functions */
      // virtual void			clear(void) = 0;
      virtual void update(void) = 0;
      virtual bool write(std::string const &msg,
                        unsigned int const x,
                        unsigned int const y) = 0;
      virtual void drawQuad(unsigned int const color,
                            unsigned int const width,
                            unsigned int const height,
                            unsigned int const x,
                            unsigned int const y) = 0;

    public: /* Accessor */
      virtual bool isInit(void) const = 0;
      virtual Arcade::Graphic::Context getContext(void) const = 0;
      virtual void setContext(Arcade::Graphic::Context context) = 0;
      virtual bool getStateKey(Arcade::Graphic::Keyboard key) const = 0;
      virtual void setKey(Arcade::Graphic::Keyboard _key) = 0;
      virtual Arcade::Graphic::Keyboard getKey(void) = 0;

    public: /* Methods */
      virtual void loop(void *param) = 0;
    };
  }
}

#endif /* !IGRAPH_HPP_ */
