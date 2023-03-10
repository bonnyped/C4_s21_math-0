CC = gcc
CFLAGS = -g -Wall  -Wextra -Werror -std=c11 -c
UNAME:=$(shell uname -s)
TEST_FLAGS = $(shell pkg-config --cflags --libs check)

all : clean s21_math.a test

test: test.o s21_math.a
ifeq ($(OS),Darwin)
	$(CC) test.o s21_math.a -o test -L. $(TEST_FLAGS)
	./test
else
	$(CC) test.o s21_math.a -o test -L. $(TEST_FLAGS) -lm
	./test
endif

test.o: test.c
ifeq ($(OS),Darwin)
	$(CC) $(CFLAGS) test.c -o test.o
else
	$(CC) $(CFLAGS) test.c -o test.o -lm
endif

test.c: 
	checkmk clean_mode=1 tests/include.file tests/*.check > test.c 
	clang-format -i -style=google test.c

s21_math.a : s21_math.c
ifeq ($(OS),Darwin)
	$(CC) -c $(CFLAGS) s21_math.c
else
	$(CC) -c $(CFLAGS) s21_math.c -lm
endif
	ar rc s21_math.a s21_math.o

gcov_report: test.c
	$(CC) -fprofile-arcs -ftest-coverage test.c s21_math.c  -o tests/gcov_report $(TEST_FLAGS)
	tests/./gcov_report
	lcov -t "test" -o tests/test.info -c -d .
	genhtml -o report tests/test.info

open:
ifeq ($(OS),Darwin)
	open -a "Google Chrome" 	report/src/index.html
else
	xdg-open report/src/index.html
endif

clang:
	clang-format -n -style=google *.c *.h

clangI:
	clang-format -i -style=google *.c *.h

leak:
ifeq ($(OS),Darwin)
	CK_FORK=no leaks -atExit -- ./test
else
	CK_FORK=no valgrind --leak-check=full -s --track-origins=yes --log-file=leak.log ./test
endif

clean:
	rm -rf *.o *.a *.out tests/*.info tests/*.gcda tests/*.gcno *.log *.html *.gc* test tests/gcov_report s21_math report test.c

rebuild: all
