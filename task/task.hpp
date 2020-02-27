#ifndef TASK_HPP
#define TASK_HPP


#define ACTIVE_CONTENDING 0
#define ACTIVE_NON_CONTENDING 1
#define INACTIVE 2

// namespace platform{
//   class Processor;
// }

#include "../platform/processor.hpp"

namespace platform {
  class Processor;
}

namespace task {
  

  
  class Task {
  private:
    int id;
    int D;
    int T;
    double C_fmax;
    double bw;
    platform::Processor * proc;
    double budget;
    double v;
    double remaining;
    double d;
    int state;
  public:

    int _state();
    void _state(int state);
    double _v();
    void _v(double v);
    
    double _bw();
    void _bw(double bw);
    void _budget(double budget);
    double _budget();
    void postpone_d();
    platform::Processor * _proc();
    void _proc(platform::Processor * p);
    int _id();
    void _id(int id);
    int _D();
    void _D(int D);
    int _T();
    void _T(int T);
    double C(double s);
    Task(int id, int D, int T, double C_fmax);
    void display();
    double utilization(double s);
    ~Task();
    int arm_act_cont_timer(double time);

    double _remaining();
    void _remaining(double remaining);
    void compute_remaining();
    void update_v();
    
  };
}
#endif
