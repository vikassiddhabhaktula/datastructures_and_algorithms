CC=g++
CFLAGS=-pipe -O2 -std=c++14
LDFLAGS=-lm
INC=-I/home/heaven/code/algorithms_specialization/course1_algorithmic_toolbox/assignment_questions/week2_algorithmic_warmup/
DEPS = 
DEFS = 
OBJ1 = 1_fibonacci_number/fibonacci.o compute_time.o
OBJ2 = 2_last_digit_of_fibonacci_number/fibonacci_last_digit.o compute_time.o
OBJ3 = 3_greatest_common_divisor/gcd.o compute_time.o
OBJ4 = 4_least_common_multiple/lcm.o  compute_time.o
OBJ5 = 5_fibonacci_number_again/fibonacci_huge.o  compute_time.o
OBJ6 = 6_last_digit_of_the_sum_of_fibonacci_numbers/fibonacci_sum_last_digit.o  compute_time.o
OBJ7 = 7_last_digit_of_the_sum_of_fibonacci_numbers_again/fibonacci_partial_sum.o  compute_time.o
OBJ8 = 8_last_digit_of_the_sum_of_squares_of_fibonacci_numbers/fibonacci_sum_squares.o  compute_time.o

%.o: %.c $(DEPS) $(DEFS)
	$(CC) $(INC) -c -o $@ $< $(CFLAGS) $(LDFLAGS) $(DEFS) 

fibonacci: $(OBJ1) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS) $(INC)
fibonacci_last_digit: $(OBJ2) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)
gcd: $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)
lcm: $(OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)
fibonacci_huge: $(OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)
fibonacci_sum_last_digit: $(OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)
fibonacci_partial_sum: $(OBJ7)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)
fibonacci_sum_squares: $(OBJ8)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(DEFS)

all: fibonacci fibonacci_last_digit gcd lcm fibonacci_huge fibonacci_sum_last_digit fibonacci_partial_sum fibonacci_sum_squares
clean:
	rm compute_time.o fibonacci fibonacci_last_digit gcd lcm fibonacci_huge fibonacci_sum_last_digit fibonacci_partial_sum fibonacci_sum_squares
