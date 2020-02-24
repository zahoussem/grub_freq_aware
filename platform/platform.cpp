#include "platform.hpp"

/*************  These are common use functions : LIMITED and HPC_MODE ***************/
namespace platform {

  /**
   * Getter of engines 
   */ 
  common::List<Processor *> *Platform::_processors(){
    return processors;
  }

  /*
   * Get the number of processors in the current platform
   * @return  The size of the current platform, i.e. number of engines  
   */
  
  int Platform::_size(){
    return processors->size;
  }
  /* 
   * Constructor of Platform 
   */ 
  Platform::Platform(){
    this->processors=new common::List<Processor *>();
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
    this->processors->add_at_head(new common::Node<Processor *> (p));
  }

  /* 
   * print the current allocation 
   */ 
  void Platform::print_alloc(){
    std::cout<<"[C-B" <<std::endl;
    for (int i=0;i<processors->size;i++)
      processors->get(i)->print_ts();
  }

  /* 
   * Find the processor according to its id 
   * @param id: The processor Identifier 
   * @return The processor having identifier id and  NULL if not found  
   */
  Processor * Platform::find_processor(int id){
    for (int i=0;i<processors->size;i++)
      if (processors->get(i)->_id()==id)
	return processors->get(i);
    return NULL;
  }

  /**  
   * setter of processors 
   * @param processors The processors to set 
   */
  void Platform::_processors(common::List<Processor *> * processors){
    this->processors = processors;
  }

  /*
   * Get a processor 
   * @param i the processor index 
   * @return The processor indexed by i 
   */ 
  Processor * Platform::get(int i){
    return processors->get(i);
  }
}


