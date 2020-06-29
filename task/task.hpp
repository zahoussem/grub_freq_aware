#ifndef TASK_HPP
#define TASK_HPP

#include <vector>

#include "../platform/processor.hpp"
namespace platform
{
  class Processor;
}

namespace task
{

  class Task
  {
  private:
    int id;
    double D;
    double T;
    double C_fmax;
    std::vector<Task *> *predependencies;
    std::vector<Task *> *postdependencies;

    platform::Processor *proc_l;

  public:
    void add_predepandency(Task *tau);
    void post_postdepandency(Task *tau);

    platform::Processor *_proc_l();
    void _proc_l(platform::Processor *);

    bool is_ready();

    int _id();
    void _id(int id);
    double _D();
    void _D(double D);
    double _T();
    void _T(double D);
    double C(double s);
    Task(int id, double D, double T, double C_fmax);
    void display();
    virtual double _bw(double s);
    ~Task();
  };
} // namespace task
#endif
