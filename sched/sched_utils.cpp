#include "sched.h"

void print_sched_current_state()
{
    dbg_section_begin("UTILS: Sched state");
    for (int i = 0; i< MAX_RQ_NUMBER; i++)
    {
        dbg_msg("UTILS:Printing Run queuee ");
        dbg_msg("UTILS:Running task : ");
        //  printf("");
        print_task(sched_maker.rq_list[i].running);
        print_task_dyna(sched_maker.rq_list[i].running);
        printf("UTILS:RQ size : %d \n",sched_maker.rq_list[i].size);
        printf("UTILS:AQ size : %d \n", sched_maker.rq_list[i].asize);

        printf("UTILS:Act-BW : %d \n", sched_maker.rq_list[i].act_bw);
        printf("UTILS:Alc-BW : %d \n", sched_maker.rq_list[i].alc_bw);
    }
    dbg_section_end();
}




// update the virtual time for a running task
void update_virtual_time_running(struct gr_rq *rq,struct struct_task_gr *tau, struct timespec *delta)
{
    struct timespec mul = spec_mul(delta,rq->act_bw/(double) tau->bw );
    tau->v = spec_add( &(tau->v), &mul);
}


// print the debuging message
void dbg_msg(char *msg){


    if (msg[0]=='N')
        printf(ANSI_COLOR_GREEN     "%s"     ANSI_COLOR_RESET "\n",msg);
    else if (msg[0]=='S')
        printf(ANSI_COLOR_BLUE     "%s"     ANSI_COLOR_RESET "\n",msg);
    else
        printf(ANSI_COLOR_RED     "%s"     ANSI_COLOR_RESET "\n",msg);
}

// print the debuging message
void dbg_msg_int(char *msg, int n){

    if (msg[0]=='N')
        printf(ANSI_COLOR_GREEN     "%s : %d"     ANSI_COLOR_RESET "\n",msg,n);
    else if (msg[0]=='S')
        printf(ANSI_COLOR_BLUE     "%s : %d"     ANSI_COLOR_RESET "\n",msg,n);
    else
        printf(ANSI_COLOR_RED     "%s : %d"     ANSI_COLOR_RESET "\n",msg,n);

}


void dbg_section_begin(char * msg){
    printf(ANSI_COLOR_RED     "%s ***************************************************"     ANSI_COLOR_RESET "\n",msg);
}

void dbg_section_end(){
    dbg_msg("***********************************************************");
}


// print a time spec
void print_spec(struct timespec t ){
    if (t.tv_sec <9999)
        printf("Time: \t sec: %ld, \t \t nsec: %ld \n",t.tv_sec, t.tv_nsec);
    else    printf("Time: \t sec: %ld, \t nsec: %ld \n",t.tv_sec, t.tv_nsec);

}

// converts from timespec to sometimeunit
uint64_t to_time_unit(struct timespec to_convert,int unit){
    uint64_t t= to_convert.tv_sec * 1000000000 /unit + to_convert.tv_nsec /unit;
    return t;
}

// converts from a given time unit to a timespec
struct timespec to_time_spec(uint64_t to_convert,int unit){
    struct timespec toret;
    toret.tv_sec =  to_convert * unit/1000000000;
    toret.tv_nsec = to_convert*unit-toret.tv_sec *1000000000;
    return toret;
}



// pick the next tak
int pick_next_task(struct gr_rq *rq, struct struct_task_gr **tau){
    if (rq->size==0)
        return SCHED_ERROR;
    *tau = rq->list[0];
    return SCHED_SUCCES;
}


// sub two timespecs
struct timespec spec_sub(const struct timespec *a, const struct  timespec *b)
{
    struct timespec d;
    d.tv_nsec = a->tv_nsec - b->tv_nsec;
    d.tv_sec =  a->tv_sec - b->tv_sec;
    if (a->tv_nsec < b->tv_nsec) {
        d.tv_nsec += 1000000000;
        d.tv_sec -= 1;
    }
    return d;
}

// add two timespecs
struct timespec spec_add(const struct timespec *a, const struct timespec *b)
{
    struct timespec s;
    s.tv_nsec = a->tv_nsec + b->tv_nsec;
    s.tv_sec = a->tv_sec + b->tv_sec;
    while (s.tv_nsec >= 1000000000) {
        s.tv_nsec = s.tv_nsec - 1000000000;
        s.tv_sec += 1;
    }
    return s;
}

// get the current time with time spec
struct timespec curr_time_spec_abs()
{
    struct timespec curr;
    clock_gettime(CLOCK_ID,&curr);
    return curr;
}

// get the current time with respect to the reference time
struct timespec curr_time_spec_ref()
{
    struct timespec curr;
    clock_gettime(CLOCK_ID,&curr);
    struct timespec diff= spec_sub(&curr,&ref);
    return diff;
}

// get the current time in microseconds
uint64_t curr_time_micro_abs()
{
    return to_time_unit(curr_time_spec_abs(),toMicro);
}

// get hte current time in microseconds with respect to the reference time
uint64_t curr_time_micro_ref(){
    return to_time_unit(curr_time_spec_ref(),toMicro);
}

// initialize teh reference time
void init_ref(){
    ref = curr_time_spec_abs();
}

// initialize a grub task
void init_gr_task(struct struct_task_gr * tau){

    /*
     *
     * compute the buddget with respect to MAX_U which is an integer
     * set the virtual time
     * set the absolute deadline
     * NB: Here every thing is set to respect the ref time and need
     * to be re"set" againt if we want to use absolute time
     *
    */

    tau->bw = (to_time_unit(tau->budget,toNano) * MAX_U) /(double)(to_time_unit(tau->period,toNano));
    tau->v = curr_time_spec_abs();
    tau->sdeadline = tau->period;
}

// refill the task budget !! (Not necessary)
void replenish_gr_task(struct struct_task_gr *tau){
    tau->remaining = tau->budget;
}

// postpone the tasks deadline
void postpone_gr_task(struct struct_task_gr *tau){
    if (DEBUG_MODE) {
        dbg_msg("UTILS: before postponing \n");
        print_spec(tau->v);
        print_spec(tau->sdeadline);
    }
    tau->adeadline =  spec_add(&(tau->v), &(tau->sdeadline));
    if (DEBUG_MODE) {
        dbg_msg("UTILS: After postponing");
        print_spec(tau->adeadline);
    }
}

// updatethe vtime
void update_gr_task_v_time(struct struct_task_gr *tau){
    struct timespec curr_time = curr_time_spec_abs();
    if (spec_cmp(&(tau->v), &curr_time)==-1)
        tau->v = curr_time;
}

// add the task budget to active budget among a runqueueue
int add_bw(struct gr_rq *rq, uint64_t bw){
    // needs to be protected by a semaphore

    if (rq->act_bw + bw > MAX_U)
        return SCHED_ERROR;
    rq->act_bw += bw; // needs to be protected by a semaphore
    return SCHED_SUCCES;
}

// sub the task budget from the active utilization
int sub_bw(struct gr_rq *rq, uint64_t bw)
{
    if (rq->act_bw - bw <0)
        return SCHED_ERROR;
    rq->act_bw -= bw; // need to be protected by a semaphore
    return SCHED_SUCCES;
}


// print the dynamique parameters of a given task
void print_task_dyna(struct struct_task_gr *tau){
    printf("[Task %d:]\n",tau->id);
    printf("B: ");
    print_spec(tau->budget);
    printf("V: ");
    print_spec(tau->v);
    printf("aD: ");
    print_spec(tau->adeadline);
    printf("] \n\n");
}

int dequeue_gr_task(struct gr_rq *rq, struct struct_task_gr *tau){
  
}

// init a runqueue
void init_gr_rq(struct gr_rq * rq, int cpu){
    rq->size = 0;
    rq->asize = 0;
    rq->act_bw = 0;
    rq->alc_bw = 0;
    rq->cpu.cpu_id = cpu;
}



void print_rq_allocated(struct gr_rq rq){
    for (int i=0;i<rq.asize;i++)
        print_task(rq.allocated[i]);
}



// arm the timer
int arm_timer(timer_t timerID, struct timespec ttf){
  // insert an event according to the time 
}

// bin packing heuristics 
int first_fit(struct gr_rq *rq_l, struct struct_task_gr *tau){
    for (int i = 0 ; i< MAX_RQ_NUMBER; i++){
        if (rq_l[i].alc_bw + tau->bw <= MAX_U){
            task_entered(&(rq_l[i]),tau);
            if (DEBUG_MODE)
                printf("UTILS: [ Task %d allocated on core %d ]\n", tau->id, rq_l[i].cpu.cpu_id);
            return SCHED_SUCCES;
        }
    }
    return SCHED_ERROR;
}
