CC=g++
CFLAGS=-pipe -O2 -std=c++11
LDFLAGS=-lm
INC=-I/home/heaven/code/algorithms_specialization/course1_algorithmic_toolbox/assignment_questions/ -I/home/vikas/exps/code/datastructures_and_algorithms/algorithms_specialization/course2_data_structures/week1_basic_data_structures
DEPS = 
OBJ1 = 1_brackets_in_code/check_brackets.o compute_time.o linked_list.o
OBJ2 = 2_tree_height/tree-height.cpp compute_time.o
OBJ3 = 3_network_simulation/process_packages.o compute_time.o
OBJ4 = 4_stack_with_max/stack_with_max_naive.o compute_time.o
OBJ5 = 5_max_sliding_window/max_sliding_window.o compute_time.o

%.o: %.c $(DEPS) 
	$(CC) $(INC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)  

1: $(OBJ1) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)  $(INC)
2: $(OBJ2) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
3: $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
4: $(OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
5: $(OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
all: 1 2 3 4 5
clean:
	rm compute_time.o 1 2 3 4 5
