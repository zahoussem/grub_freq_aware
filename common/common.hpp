#ifndef COMMON_HPP
#define COMMON_HPP



//#define LIMITED_MODE
#define HPC_MODE


#include <stdio.h>
#include <iostream>

#define DEBUG_

// Taskset code generator 
#define TOFILE 0
#define CONSOLE 1


// Processor vars :

#define PREEMPTIVE 0
#define NPREEMPTIVE 1
#define EDF  0
#define FP 1


// List vars
#define  VOLA 0
#define  SAVE 1


// Subtasks Node type 
#define CONDITION 0
#define CCONDITION 4
#define ALTERNATIVE 1
#define COMPUTE 2
#define DUMMY 3



// Analysis vars 
#define EXACT_DBF  0
#define BARUAH_APPROX 1
#define NON_PREEMP 2


#define EXACT_PREEMP  0
#define APROX_PREEMP  1
#define EXACT_NPEEMP  2

// DEADLINE assignment heusitics
#define FAIR 0
#define PROP 1



// TAGs 
#define GPU 1
#define CPU 2
#define DLA 3
#define PVA 4
#define MEMCPY 5 



#define SORT_UTI_DESC  0
#define SORT_UTI_CROI  1
#define SORT_PREMP_AWARE  2


// Alloc heuristics vars
// : Common
#define BF 0
#define WF 1
#define FF 2
#define NF 3
// :  DAG Model 
#define RANDOM 0
#define PARR 1
#define RELATION 0
#define PARTIAL 1
// :  Limited Preemption Model
#define ELIM 1
#define NO_ELIM 0


// Sub-task generation vars
#define PROTECT_READ 0
#define PROTECT 0
#define UNPROTECT 1
#define PROTECT_WRITE 0 




void PRINT_DEBUG(std::string str);
void PRINT_DEBUG_(std::string str);
void PRINT_WARNING(std::string str);
void fatal_error(int ErrorCode, std::string Message);
#endif


