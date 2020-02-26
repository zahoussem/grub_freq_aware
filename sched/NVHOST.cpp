#include "NVHOST.h"

int find_task_rq(int tid, struct struct_task_gr **tau, struct gr_rq **rq){
    for (int i=0;i<MAX_RQ_NUMBER;i++){
        for (int j =0 ; j<sched_maker.rq_list[i].asize;j++){
            if (sched_maker.rq_list[i].allocated[j]->id == tid)
            {
                *tau = sched_maker.rq_list[i].allocated[j];
                *rq = &sched_maker.rq_list[i];
                return SCHED_SUCCES;
            }
        }
    }
    return SCHED_ERROR;
}


int GPU_SIGNAL_HANDLER (int signo, int tid, struct struct_task_gr *task){

    struct struct_task_gr *tau;
    struct gr_rq *rq;
    int f=find_task_rq(tid,&tau,&rq);

    int res;
    switch(signo) {


    case TASK_ENTERED:
        if (DEBUG_MODE) dbg_msg("NVHOST: Task entry");
        res= first_fit(sched_maker.rq_list,task);
        if (res){
            dbg_msg("NVHOST: Error: Task has not been allocated");
            return SCHED_ERROR;
        }
        return SCHED_SUCCES;
        break;



    case TASK_EXITED:
        if (DEBUG_MODE) dbg_msg("NVHOST: Task exit");
        if (f){
            if (DEBUG_MODE) dbg_msg("NVHSOT: Error: Task not found");
            return SCHED_ERROR;
        }
        res = task_exited(rq,tid);
        if (res){
            if (DEBUG_MODE)  dbg_msg("NVHSOT: Error: Task can not exit");
            return SCHED_ERROR;
        }
        return SCHED_SUCCES;
        break;


    case TASK_ARRIVAL:
        if (DEBUG_MODE) dbg_msg("NVHOST: Task arrival");
        if (f){
            if (DEBUG_MODE) dbg_msg("NVHSOT: Error: Task not found");
            return SCHED_ERROR;
        }
        task_arrival(rq,tau);
        break;



    case TASK_END:
        if (DEBUG_MODE) dbg_msg("NVHOST: Task end");
        if (f){
            if (DEBUG_MODE) dbg_msg("NVHSOT: Error: Task not found");
            return SCHED_ERROR;
        }
        int res= task_end(rq,tau);
        if (res){
            if (DEBUG_MODE) dbg_msg("NVHSOT: Error: Task can not ended");
            return SCHED_ERROR;
        }
        break;


    default :
        if (DEBUG_MODE) dbg_msg("NVHOST: Error: Unknown Signal");
    }
}
