CC=g++
CFLAGS=-pipe -O2 -std=c++14
LDFLAGS=-lm
INC=-I/home/heaven/code/algorithms_specialization/course1_algorithmic_toolbox/assignment_questions/
DEPS = 
OBJ1 = 1_money_change/change.o compute_time.o
OBJ2 = 2_maximum_value_of_the_loot/fractional_knapsack.o compute_time.o
OBJ3 = 3_car_fueling/car_fueling.o compute_time.o
OBJ4 = 4_maximum_advertisement_revenue/dot_product.o  compute_time.o
OBJ5 = 5_collecting_signatures/covering_segments.o  compute_time.o
OBJ6 = 6_maximum_number_of_prizes/different_summands.o  compute_time.o
OBJ7 = 7_maximum_salary/largest_number.o  compute_time.o

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
7: $(OBJ7)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 
all: 1 2 3 4 5 6 7
clean:
	rm compute_time.o 1 2 3 4 5 6 7
