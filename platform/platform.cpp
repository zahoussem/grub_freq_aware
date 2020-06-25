#include "platform.hpp"

/*************  These are common use functions : LIMITED and HPC_MODE ***************/
namespace platform {

  /**
   * Getter of engines 
   */ 
  std::vector<Processor *> *Platform::_processors(){
    return processors;
  }

  /*
   * Get the number of processors in the current platform
   * @return  The size of the current platform, i.e. number of engines  
   */
  
  int Platform::_size(){
    return processors->size();
  }
  /* 
   * Constructor of Platform 
   */ 
  Platform::Platform(){
    this->processors=new std::vector<Processor *>();
  }

  /* 
   * Destructor of the current platform 
   */ 
  Platform::~Platform(){
  };

  /* 
   * Add a processor to the current processor List 
   * @param p: Processor to add 
   */
  void Platform::add(Processor *p){
    this->processors->push_back(p);
  }

  /* 
   * print the current allocation 
   */ 
  void Platform::print_alloc(){
    std::cout<<"[C-B" <<std::endl;
    for(Processor * p : (*processors)) 
      p->print_tq();
  }

  /* 
   * Find the processor according to its id 
   * @param id: The processor Identifier 
   * @return The processor having identifier id and  NULL if not found  
   */
  Processor * Platform::find_processor(int id){
     for(Processor * p : (*processors)) 
      if (p->_id()==id)
	return p;
    return NULL;
  }

  /**  
   * setter of processors 
   * @param processors The processors to set 
   */
  void Platform::_processors(std::vector<Processor *> * processors){
    this->processors = processors;
  }

  /*
   * Get a processor 
   * @param i the processor index 
   * @return The processor indexed by i 
   */ 
  Processor * Platform::get(int i){
    return processors->at(i);
  }


  bool Platform::order_processors(int order){

    // Houssam : I need to write this function 
    //   // Using lambda expressions in C++11
    // sort(vec.begin(), vec.end(), [](const MyStruct& lhs, const MyStruct& rhs) {
    //   return lhs.key < rhs.key;
    // });

    return false;
  }
}


