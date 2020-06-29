#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "processor.hpp"

#include <vector>

namespace platform{
  
  class Processor;
  
  class Platform{
  private:

    std::vector<Processor *> *processors;
    double cost=0;
      
  public:
    std::vector<Processor *> *_processors();
    int _size();
    Platform();
    ~Platform();
    void add(Processor *p);
    void print_alloc();
    Processor * find_processor(int id);
    void _processors(std::vector<Processor *> * processors);
    Processor * get(int i);
    bool order_processors(int order);
  
  };
}
#endif
