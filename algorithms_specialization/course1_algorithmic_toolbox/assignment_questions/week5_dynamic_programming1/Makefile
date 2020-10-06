CC=g++
CFLAGS=-pipe -O2 -std=c++14
LDFLAGS=-lm
INC=-I/home/heaven/code/algorithms_specialization/course1_algorithmic_toolbox/assignment_questions/
DEPS = 
OBJ1 = 1_money_change_again/change_dp.o compute_time.o
OBJ2 = 2_primitive_calculator/primitive_calculator.o compute_time.o
OBJ3 = 3_edit_distance/edit_distance.o compute_time.o
OBJ4 = 4_longest_common_subsequence_of_two_sequences/lcs2.o  compute_time.o
OBJ5 = 5_longest_common_subsequence_of_three_sequences/lcs3.o  compute_time.o

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
