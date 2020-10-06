CC=g++
CFLAGS=-pipe -O2 -std=c++14
LDFLAGS=-lm
INC=-I/home/heaven/code/algorithms_specialization/course1_algorithmic_toolbox/assignment_questions/
DEPS = 
OBJ1 = 1_maximum_amount_of_gold/knapsack.o compute_time.o
OBJ2 = 2_partitioning_souvenirs/partition3.o compute_time.o
OBJ3 = 3_maximum_value_of_an_arithmetic_expression/placing_parentheses.o compute_time.o

%.o: %.c $(DEPS) 
	$(CC) $(INC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)  

1: $(OBJ1) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)  $(INC)
2: $(OBJ2) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
3: $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
all: 1 2 3
clean:
	rm compute_time.o 1 2 3
