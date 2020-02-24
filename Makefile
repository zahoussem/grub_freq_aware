CC=g++
CFLAGS= -Wall -std=c++11 -g
EXECUTABLE=list
DOXYGEN =doxygen

SOURCES = main.cpp task/task.cpp platform/processor.cpp			\
platform/platform.cpp task/taskset.cpp task/job.cpp common/list.cpp	\
common/common.cpp


list: common/common.o common/list.o   task/task.o task/taskset.o task/job.o   platform/platform.o platform/processor.o main.cpp
	$(CC) $(CFLAGS) -g -Wall -o $(EXECUTABLE) $(SOURCES)

%.o : %.cpp
	$(CC) -std=c++11 -c -o $@ $^

clean:
	rm -rf *.o *.gch $(EXECUTABLE)
	rm -rf common/*.o
	rm -rf task/*.o
	rm -rf platform/*.o gen

leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)

docs: Doxyfile
	$(DOXYGEN) $^
