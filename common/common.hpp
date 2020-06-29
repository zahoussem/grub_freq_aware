#ifndef COMMON_HPP
#define COMMON_HPP



//#define LIMITED_MODE
#define HPC_MODE


#include <stdio.h>
#include <iostream>

#include "../sched/scheduler.hpp"


namespace sched {
    class Scheduler;
}

sched::Scheduler * _scheduler();


#define DEBUG_

// Taskset code generator 
#define TOFILE 0
#define CONSOLE 1

// List vars
#define  VOLA 0
#define  SAVE 1

// Task staets
#define ACTIVE_CONTENDING 0
#define ACTIVE_NON_CONTENDING 1
#define INACTIVE 2


// Alloc heuristics vars
#define BF 0
#define WF 1
#define FF 2
#define NF 3

#define TASK_ARRIVAL 0
#define TASK_KILLED 1 
#define TASK_FINISHED 2 
#define ACTIVE_STATE_EXHAUSTED 3 
#define CONTENDING_STATE_EXITID 4
#define TASK_REBOOTED 5 



void PRINT_DEBUG(std::string str);
void PRINT_DEBUG_(std::string str);
void PRINT_WARNING(std::string str);
void fatal_error(int ErrorCode, std::string Message);
#endif


