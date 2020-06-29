#include "taskset.hpp"

namespace task
{

  /***** These are common use functions : LIMITED and HPC_MODE *****/

  /**
   *  generate randomly a double with values between a and b assumption that b>a
   *  @param a : the first value 
   *  @param b : the second value 
   *  @return a random value between a and b 
   */
  double Taskset::randomDouble(double a, double b)
  {
    return (a + (b - a) * (rand() / (double)RAND_MAX));
  }

  bool Taskset::check_acceptance(Task *tau, double speed)
  {
    if (bw(speed) > 1)
      return false;
    return true;
  }

  /**
   * Calculate the utilization of all the taskset's task.
   * @return The Taskset utilization.
   */
  double Taskset::bw(double speed)
  {
    double U = 0;
    for (std::size_t i = 0; i < list->size(); ++i)
      U += list->at(i)->_bw(speed);
    return U;
  }

  /**
   * Getter of size 
   */
  int Taskset::_size()
  {
    return list->size();
  }

  /**
   * @return the list of tasks 
   */
  std::vector<Task *> *Taskset::_list()
  {
    return list;
  }

  /**
   * set the list of tasks
   */
  void Taskset::_list(std::vector<Task *> *list)
  {
    this->list = list;
  }

  /** 
   * Adds a task to the current taskset 
   * @param tau The task to add
   */
  void Taskset::add(Task *tau)
  {
    list->push_back(tau);
  }

  /** 
   * removes a task to bthe current taskset 
   * @param tau The task to remove
   */
  bool Taskset::remove(Task *tau)
  {
    // std::vector<Task *>::iterator it = std::find(list->begin(), list->end(), tau);
    // if (it != list->end())
    //   {
    // 	  list->erase(it);
    // 	  return true;
    //   }
    // Houssam : Need to complete this function
    return false;
  }

  /** 
   * Gets the task pointed by i 
   * @param i The task index 
   * @return the task indexed by i 
   */
  Task *Taskset::get(int i)
  {
    return list->at(i);
  }

  /**
   * Constructor of the task
   * @param id the ID of the task set
   */

  Taskset::Taskset(int id)
  {
    this->id = id;
    this->list = new std::vector<Task *>();
  }

  /**
   * Initialize a task set with id -1 
   */
  Taskset::Taskset()
  {
    this->id = -1;
    this->list = new std::vector<Task *>();
  }

  /**
   * Removes and destroys tasks
   * @return true if succeeded, otherwise false
   */
  bool Taskset::destroy_tasks()
  {
    while (list->size() > 0)
    {
      Task *s = list->at(0);
      bool res = remove(s);
      if (!res)
        return false;
      delete s;
    }
    return true;
  }

  /**
   * Destroy the Takset
   */
  Taskset::~Taskset()
  {
    delete list;
  }

  /**
   * Calculate the Least common multiple (LCM) of the 2 given numbers
   * @param a First number
   * @param b Second number
   * @return LCM of a and b
   */
  long int Taskset::LCM(long int a, long int b)
  {
    long int x = a;
    long int y = b;
    long int t;
    while (b != 0)
    {
      t = b;
      b = a % b;
      a = t;
    }
    return (x * y) / a;
  }

  /**
   * Calculate the hyperperiod, LCM of all periods of the curren
   * task set
   * @return The hyperperiod
   */
  long int Taskset::hyperperiod()
  {
    long int hyper = 1;
    for (Task *tau : (*list))
      hyper = LCM(hyper, tau->_T());
    return hyper;
  }

  /**
   * Read the task set from  file arg  
   * @param arg : the path to the file
   */
  void Taskset::read(std::string arg)
  {
    // Houssam : Reads a task from a task set
  }

  /**
   * Write  the task set to the file  arg 
   * @param arg : the path to the file
   */
  void Taskset::write(std::string arg)
  {
    // Houssam : Save the task set in a file
  }

  /**
   * Prints task set 
   */
  void Taskset::display()
  {
    for (Task *tau : (*list))
      tau->display();
  }

  /**
   * Constructor of a taskset from a file 
   * @param path the path to the taskset file
   */
  Taskset::Taskset(std::string path)
  {
    // Houssam : Load task from a text file
  }

  /**
   * Sorts tasks by utilization in in/decreasing order
   * @param method 1: increasing order
   *               2: decreasing order
   * @param speed the processor speed
   *@return taskset sorted
   */
  void Taskset::sort_by_U(int method)
  {
  }

  /** 
   * Sort tasks according to their relative deadline
   */
  void Taskset::sort_by_D()
  {
  }

} // namespace task
