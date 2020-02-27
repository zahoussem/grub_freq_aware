CC=g++
CFLAGS= -Wall -std=c++11 -g
EXECUTABLE=list
DOXYGEN =doxygen

SOURCES = main.cpp task/task.cpp platform/processor.cpp		    \
platform/platform.cpp task/taskset.cpp task/job.cpp common/list.cpp \
common/common.cpp sim_engine/event.cpp sim_engine/sim_engine.cpp    \
task/runqueue.cpp sched/sched.cpp 


list: common/common.o common/list.o task/runqueue.o  sim_engine/event.o sched/sched.o sim_engine/sim_engine.o  task/task.o task/taskset.o task/job.o platform/platform.o platform/processor.o main.cpp
	$(CC) $(CFLAGS) -g -Wall -o $(EXECUTABLE) $(SOURCES)

%.o : %.cpp
	$(CC) -std=c++11 -c -o $@ $^

clean:
	rm -rf *.o *.gch $(EXECUTABLE)
	rm -rf common/*.o
	rm -rf task/*.o
	rm -rf platform/*.o
	rm -rf sim_engine/*.o
	rm -rf sched/*.o
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)

docs: Doxyfile
	$(DOXYGEN) $^
