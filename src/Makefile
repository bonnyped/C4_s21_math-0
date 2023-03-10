CC = gcc
CFLAGS = -g -Wall  -Wextra -Werror -std=c11 -c
OS:=$(shell uname)
TEST_FLAGS = $(shell pkg-config --cflags --libs check)
LM = -lm 
OPEN = xdg-open
LEAK = valgrind --leak-check=full -s --track-origins=yes --log-file=leak.log

ifeq ($(OS),Darwin)
	LM = 
	OPEN = open -a "Google Chrome"
	LEAK = leaks -atExit --
endif

all : clean s21_math.a test

test: test.o s21_math.a
	$(CC) test.o s21_math.a -o test -L. $(TEST_FLAGS) $(LM)
	./test

test.o: test.c
	$(CC) $(CFLAGS) test.c -o test.o $(LM)

test.c: 
	checkmk clean_mode=1 tests/include.file tests/*.check > test.c 
	clang-format -i -style=google test.c

s21_math.a : s21_math.c
	$(CC) -c $(CFLAGS) s21_math.c $(LM)
	ar rc s21_math.a s21_math.o

gcov_report: test.c
	$(CC) -fprofile-arcs -ftest-coverage test.c s21_math.c  -o tests/gcov_report $(TEST_FLAGS)
	tests/./gcov_report
	lcov -t "test" -o tests/test.info -c -d .
	genhtml -o report tests/test.info

open:
	$(OPEN) report/src/index.html

clang:
	clang-format -n -style=google *.c *.h

clangI:
	clang-format -i -style=google *.c *.h

leak:
	CK_FORK=no $(LEAK) ./test

clean:
	rm -rf *.o *.a *.out tests/*.info tests/*.gcda tests/*.gcno *.log *.html *.gc* test tests/gcov_report s21_math report test.c

rebuild: all
