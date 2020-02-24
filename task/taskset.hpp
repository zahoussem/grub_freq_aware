#ifndef TASKSET_HPP
#define TASKSET_HPP

#include "../common/list.hpp"
#include "../common/common.hpp"

#include "task.hpp"
#include "../platform/processor.hpp"

#include <iostream>
#include <fstream> 
#include <sstream>

namespace task {
  class Task;

  class Taskset{
  private:
    common::List<Task *> *list;
    int id;
  public:
    
    bool destroy_tasks();
    common::List<double> *UUniFastDiscard(int nbT,double u,int nbSet);
    common::List<double> *UUniFast(int nbT,double u);
    double  randomDouble(double a, double b);
    

    double utilization(double speed);
    int _size();
    common::List<Task *> *_list();
    void _list(common::List<Task *> * list);
    void  add(Task * tau);
    bool  remove(Task * tau);
    void merge(Taskset *ts);
    Task * get(int i);
    Taskset(int id);
    Taskset();
    ~Taskset();
    long int LCM(long int a, long int b);
    long int hyperperiod();
    void read(std::string arg);
    void write(std::string arg);
    void display();

    void sort(int METHOD); 
    void sort_by_U(int method, double speed);
    void sort_by_D();
    
    Taskset(std::string path);
    void txt_save( std::string path);
  
    Taskset* params_copy();
    Task * find_task_by_deadline(int D);
    void generate_taskset(int nbT, double  U, double DP);


  };
}
#endif
