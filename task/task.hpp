#ifndef TASK_HPP
#define TASK_HPP



#include "../platform/processor.hpp"
#include "server.hpp"

namespace platform {
  class Processor;
}

namespace task {
  

  
  class Task {
  private:
    int id;
    double D;
    double T;
    double C_fmax;
    platform::Processor * proc;
    Server *server;
    
  public:
    Server * _server();
    void _server(Server * server);
    platform::Processor * _proc();
    void _proc(platform::Processor * p);
    int _id();
    void _id(int id);
    double _D();
    void _D(double D);
    double _T();
    void _T(double D);
    double C(double s);
    Task(int id, double D, double T, double C_fmax, Server * s);
    void display();
    double utilization(double s);
    ~Task(); 
  };
}
#endif
