#include "taskset.hpp"

namespace task{
  
  /***** These are common use functions : LIMITED and HPC_MODE *****/
  
  /**
   *  generate randomly a double with values between a and b assumption that b>a
   *  @param a : the first value 
   *  @param b : the second value 
   *  @return a random value between a and b 
   */
  double  Taskset:: randomDouble(double  a, double  b) {
    return  (a + (b - a)*(rand() / (double) RAND_MAX));
  }

  
  /**
   *  UUniFast generation function
   *  @param nbT : The number of tasks to generate
   *  @param u: the total utilization 
   *  @return a List of nbT utilizations
   */
  // Houssam : I am not sure that Uunifast is correct 
  common::List<double> *Taskset::UUniFast(int nbT, double u){
    common::List<double> *utilizations= new common::List<double>();
    double sumU = u;
    double nextSumU=0;
    for (int i=1;i<nbT; i++){
      double t= randomDouble (0,1);
      nextSumU = sumU * pow(t, 1.0 / (double(nbT-i))) ; 
      common::Node<double> * ls  = new common::Node<double>(sumU - nextSumU);
      utilizations->add_at_head(ls);
      sumU = nextSumU;
    }
    utilizations->add_at_head(new common::Node<double>(sumU));
    return utilizations;
  }

  /**
   *  UUniFastDiscard generation function
   *  Input: total utilisation, the number of tasks and the number of taskset
   */
  common::List<double> *Taskset::UUniFastDiscard(int nbT,double  u, int nbSet){
    common::List<common::List<double>*> *sets= new common::List<common::List<double>*>();
    while(sets->size < nbSet){
      int j=0, succ=0; 
      common::List<double> *utilizations= UUniFast(nbT,u);// bloc utilizations 
      while(utilizations->get(j)<= 1 ){
	j++;
	if(j==nbT){ succ=1; break;}
      }
      if(succ){ sets->add_at_head(new common::Node<common::List<double>*>(utilizations));}
    }
    return sets->get(0); 
  }

  /**
   * Calculate the utilization of all the taskset's task.
   * @return The Taskset utilization.
   */
  double Taskset::utilization(double speed){
    double U = 0;
    for (int i=0; i< list->size ; i++)
      U +=  list->get(i)->utilization(speed);
    return U;
  }

  /**
   * Getter of size 
   */ 
  int Taskset::_size(){
    return list->size;
  }

  /**
   * @return the list of tasks 
   */
  common::List<Task *> *Taskset::_list(){
    return list;
  }

  /**
   * set the list of tasks
   */
  void Taskset::_list(common::List<Task *> * list){
    this->list = list;
  }

  /** 
   * Adds a task to the current taskset 
   * @param tau The task to add
   */
  void Taskset:: add(Task * tau){
    list->add_at_tail(new common::Node<Task *> (tau));
  }

  /** 
   * removes a task to bthe current taskset 
   * @param tau The task to remove
   */
  bool  Taskset::remove(Task * tau){
    return list->remove(tau); 
  }

  /** 
   *  Merges two task sets : be carefull about the calculated params
   *  @param tau The task to merge with the current 
   */
  void Taskset::merge(Taskset *ts){
    list->merge(ts->_list()); 
  }
  
  Task * Taskset::get(int i){
    return list->get(i);
  }
  
  /**
   * Constructor of the task
   * @param id the ID of the task set
   */

  Taskset::Taskset(int id){
    this->id = id;
    this->list = new common::List<Task *>();	
  }
  
  /**
   * Initialize a task set with id -1 
   */
  Taskset::Taskset(){
    this->id = -1;
    this->list = new common::List<Task *>();
  }



  
  bool Taskset::destroy_tasks(){
    while (list->size > 0) {
      Task * s = list->get(0);
      bool res = list->remove(s);
      if (!res)
	return false;
      delete s;
    }
    return true;
  }

  
  /**
   * Destroy the Takset
   */ 
  Taskset::~Taskset(){
    delete list;
  }

  /**
   * Calculate the Least common multiple (LCM) of the 2 given numbers
   * @param a First number
   * @param b Second number
   * @return LCM of a and b
   */
  long int Taskset::LCM(long int a, long int b){
    long int x =a;
    long int y = b;
    long int t;
    while (b != 0) {
      t = b;
      b = a % b;
      a = t;
    }
    return (x*y)/a;
  }

  /**
   * Calculate the hyperperiod, LCM of all periods of the curren
   * task set
   * @return The hyperperiod
   */
  long int Taskset::hyperperiod(){
    long int hyper = 1;
    for (int i=0; i< list->size ; i++)
      hyper = LCM(hyper,list->get(i)->_T());
    return hyper;
  }
  
  /**
   * Read the task set from  file arg  
   * @param arg : the path to the file
   */
  void Taskset::read(std::string arg){
    
  }

  /**
   * Write  the task set to the file  arg 
   * @param arg : the path to the file
   */
  void Taskset::write(std::string arg){
  }

  /**
   * Print task set 
   */
  void Taskset::display(){
    for (int i=0; i< list->size ; i++)
      list->_get(i)->display();
  }

  
    Taskset::Taskset(std::string path){
    }

  

  
 /**
   *sort tasks by utilization in in/decreasing order
   * 1: increasing order
   * 2: decreasing order
   *@return taskset sorted
   */
  void Taskset::sort_by_U(int method, double speed){
    
    common::List<task::Task*> *l_p = new common::List<task::Task*>(); 
    while (list->size > 0) {
      task::Task *max_p = list->get(0);
      double max_d = max_p->utilization(speed);
      for (int j = 1; j <list->size; j++) {
  	if (list->get(j)->utilization(speed) > max_d) {
  	  max_d = list->get(j)->utilization(speed);
  	  max_p = list->get(j);
  	}
      }
      list->remove(max_p);
      if(method == 1){
	l_p->add_at_head(new common::Node<task::Task *>(max_p));
      }else
	{
	  l_p->add_at_tail(new common::Node<task::Task *>(max_p));
	}
    }
    common::List<task::Task*> *to_del = this->_list();
    this->_list(l_p);
    delete to_del;
  }

  void  Taskset::sort_by_D(){
    common::List<Task *>  *s_tasks= new common::List<Task *>(); 
    while (list->size>0){
      Task * min= this->get(0);
      for (int p = 0; p < this->_size(); p++)
	if(this->get(p)->_D()<min->_D())
	  min =this->get(p);	 
      s_tasks->add_at_tail(new common::Node<Task *>(min));
      list->remove(min);
    }
    this->list = s_tasks;
  }

  /*
   * Generate a task of sets 
   * @param nbT : The number of tasks 
   * @param U : The total utilization 
   */
  void Taskset::generate_taskset(int nbT, double  U, double DP){
    int periods[6]= {1000,1500,2000,3000,4000,6000};
    common::List<double> *utilizations=   UUniFastDiscard(nbT, U, 8);// task utilizations   
    for( int j=0; j<utilizations->size; j++){
      int T= periods[(rand() % (sizeof(periods)/sizeof(int)))]; //generate T
      int D= (int)(randomDouble(T*DP,T));
      int C= (int) randomDouble(1,5);
      // Houssam : Need to generate execution time 
      task::Task * tau = new task::Task(j,D,T,C); // create task
      this->add(tau); 
    } 
  }

}
