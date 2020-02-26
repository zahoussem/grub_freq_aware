#ifndef TASK_HPP
#define TASK_HPP

namespace platform{
  class Processor;
}

namespace task {
  class Taskset;

  class Task {
  private:
    int id;
    int D;
    int T;
    double C_fmax;

  public:
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
    int arm_act_cont_timer(task::Task *tau);

  };
}
#endif
