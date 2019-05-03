#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class eventListener
{
public:
  virtual void onClose();

  virtual void onMouseButton(sf::Event::MouseButtonEvent, int&);
};

struct event_source
{
  int moveStatus;

  event_source(sf::Window& w)
    : window(&w)
  { }

  void
  listen(eventListener& l)
  {
    listeners.push_back(&l);
  }

  void poll()
  {
    sf::Event e;
    while (window->pollEvent(e))
      process(e);
  }

  void process(sf::Event const& e)
  {
    switch (e.type) {
    case Event::Closed:
      return notify([e](eventListener* l) { l->onClose(); });

    case Event::MouseButtonPressed:
      return notify([e](eventListener* l) { l->onMouseButton(e.mouseButton, moveStatus); });

    default: break;
    }
  }

template<typename T>
 void notify(T fn)
 {
   for (eventListener* l : listeners)
     fn(l);
 }

 sf::Window* window;

 std::vector<eventListener*> listeners;

};
