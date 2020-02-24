#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "../common/list.hpp"
#include "processor.hpp"
namespace platform{
  class Platform{
  private:
    common::List<platform::Processor *> *processors;
    double cost=0;
      
  public:
    task::Taskset * not_yet_allocated = new task::Taskset();
  
    common::List<Processor *> *_processors();
    int _size();
    Platform();
    ~Platform();
    void add(Processor *p);
    void print_alloc();
    Processor * find_processor(int id);
    void _processors(common::List<Processor *> * processors);
    Processor * get(int i);
    bool order_processors();
  
  };
}
#endif
