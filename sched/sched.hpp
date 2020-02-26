#ifndef SCHED_H
#define SCHED_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define MAX_U 100000
#define MAX_TASK_NUMBER 6
#define CORE_NUMBER 1
#define MAX_RQ_NUMBER CORE_NUMBER


#define toSec       1000000000
#define toMillis    1000000
#define toMicro     1000
#define toNano      1

#define CLOCK_ID CLOCK_REALTIME

#define SCHED_ERROR 1
#define SCHED_SUCCES 0

#define DEBUG_MODE  1




struct timespec ref;
struct grub_scheduler sched_maker;




struct struct_task_gr {
    uint32_t id;
    struct timespec budget;
    struct timespec period;
    struct timespec tdeadline;
    struct timespec sdeadline;

    struct timespec remaining; // not needed to do grub
    uint64_t bw;
    struct timespec v;
    struct timespec adeadline;
    timer_t act_con_timer;
};

struct cpu {
    uint8_t cpu_id;
};

struct gr_rq {
    struct struct_task_gr *list[MAX_TASK_NUMBER];
    struct struct_task_gr *allocated[MAX_TASK_NUMBER];
    struct cpu cpu;
    uint32_t size;
    uint32_t asize;
    uint64_t act_bw;
    uint64_t alc_bw;
    struct struct_task_gr *running;
    timer_t main_timer;
};

struct act_cont_grp{
    struct struct_task_gr *tau;
    struct gr_rq *rq;
    struct timespec end_time;
};

struct act_cont_set{
    struct act_cont_grp list[MAX_TASK_NUMBER];
    uint32_t size;
};

struct grub_scheduler {
    struct gr_rq rq_list[MAX_RQ_NUMBER];
    struct act_cont_set set;
};

int first_fit(struct gr_rq *, struct struct_task_gr *);
int task_entered(struct gr_rq *, struct struct_task_gr *);
int task_exited(struct gr_rq *, uint32_t);


// active cont_handler; not reported!! is static
// main_timer_handler : not reported may be set to static
int init_main_timer();
int cancel_main_timer();
static int init_cont_timer( timer_t *);
int arm_timer(timer_t , struct timespec);
void dbg_msg(char *);
void dbg_msg_int(char *,int);
void dbg_section_begin(char *);
void dbg_section_end();


// time operations
void print_spec(struct timespec);
uint64_t to_time_unit(struct timespec ,int );
struct timespec to_time_spec(uint64_t ,int );
struct timespec spec_sub(const struct timespec *, const struct  timespec *);
struct timespec spec_add(const struct timespec *, const struct  timespec *);
struct timespec curr_time_spec_abs();
struct timespec curr_time_spec_ref();
uint64_t curr_time_micro_abs();
uint64_t curr_time_micro_ref();
int spec_cmp(const struct timespec *, struct timespec *);
struct timespec spec_mul(struct timespec *, double);


void init_ref();
void init_gr_task(struct struct_task_gr *);


// grub scheduling operations
void replenish_gr_task(struct struct_task_gr *);
void postpone_gr_task(struct struct_task_gr *);
void update_gr_task_v_time(struct struct_task_gr *);
int add_bw(struct gr_rq *, uint64_t );
int sub_bw(struct gr_rq *, uint64_t );
// active_cont_handler : not described here because it may be static
int set_task_active_cont(struct gr_rq *, struct struct_task_gr *);
void print_task(struct struct_task_gr *);
void print_task_dyna(struct struct_task_gr *);
int enqueue_gr_task(struct gr_rq *, struct struct_task_gr *);
int task_arrival(struct gr_rq *, struct struct_task_gr *);
int dequeue_gr_task(struct gr_rq *, struct struct_task_gr *);
// budget_exhausted controller: not described here because it may be static
int pick_next_task(struct gr_rq *,struct struct_task_gr **);
void init_gr_rq(struct gr_rq *, int );
void print_rq(struct gr_rq);
int task_end(struct gr_rq *,struct struct_task_gr *);
int add_act_cont_grp(struct act_cont_set *,struct  act_cont_grp);
int rm_act_cont_grp(struct act_cont_set *, struct  act_cont_grp);
void print_grp(struct act_cont_grp *);
void print_grp_set(struct act_cont_set *);
void init_act_cont_set(struct act_cont_set *);
int pick_next_active_cont_grp(struct act_cont_set *,struct act_cont_grp **);

void update_virtual_time_running(struct gr_rq*, struct struct_task_gr *, struct timespec *);
int resched(struct gr_rq *);
void print_rq_allocated(struct gr_rq );
int init_main_scheduler();
void print_sched_current_state();

#endif
