CC=g++
CFLAGS=-pipe -O2 -std=c++14
LDFLAGS=-lm
INC=-I/home/heaven/code/algorithms_specialization/course1_algorithmic_toolbox/assignment_questions/
DEPS = 
OBJ1 = 1_binary_search/binary_search.o compute_time.o
OBJ2 = 2_majority_element/majority_element.o compute_time.o
OBJ3 = 3_improving_quicksort/sorting.o compute_time.o
OBJ4 = 4_number_of_inversions/inversions.o  compute_time.o
OBJ5 = 5_organizing_a_lottery/points_and_segments.o  compute_time.o
OBJ6 = 6_closest_points/closest.o  compute_time.o

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
6: $(OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
all: 1 2 3 4 5 6 
clean:
	rm compute_time.o 1 2 3 4 5 6 
