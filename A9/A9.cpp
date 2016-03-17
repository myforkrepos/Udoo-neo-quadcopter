#include "A9.hpp"
#include <iostream>

A9::A9()
{
  std::cout << "A9 constructor" << std::endl;

  serialport.AddObserver(*this);
  serialport.start();

  network.AddObserver(*this);
  network.start(5555);
}
A9::~A9()
{
  std::cout << "A9 destructor" << std::endl;
}

void A9::update()
{
    if(serialport.hasChanged())
      std::cout << "From M4: " << serialport.getLine() << std::endl;
    if(network.hasChanged())
      std::cout << "From Android: " << network.getMessage() << std::endl;
}