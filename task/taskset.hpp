#ifndef TASKSET_HPP
#define TASKSET_HPP

#include "../common/list.hpp"
#include "../common/common.hpp"

#include "task.hpp"
#include "../platform/processor.hpp"

#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>
namespace task {
  class Task;

  class Taskset{
  private:
    int id;
    std::vector<Task *> *list;
  public:
    
    bool destroy_tasks();
    std::vector<double> *UUniFastDiscard(int nbT,double u,unsigned int nbSet);
    std::vector<double> *UUniFast(int nbT,double u);
    double  randomDouble(double a, double b);
    bool check_acceptance(Task *tau);

    double utilization(double speed);
    int _size();
    std::vector<Task *> *_list();
    void _list(std::vector<Task *> * list);
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
