CC = gcc
CFLAGS = -g -Wall  -Wextra -Werror -std=c11 -c
UNAME:=$(shell uname -s)
TEST_FLAGS = $(shell pkg-config --cflags --libs check)

all : clean s21_math.a test gcov_report

test: test.o s21_math.a
ifeq ($(OS),Linux)
	$(CC) test.o s21_math.a -o test -L. $(TEST_FLAGS) -lm
else
	$(CC) test.o s21_math.a -o test -L. $(TEST_FLAGS)
endif

debug: main.o s21_math.a
	$(CC) main.o s21_math.a -o debug -L. $(TEST_FLAGS) -lm
	./debug
main.o:
	$(CC) $(CFLAGS) main.c -o main.o -lm

test.o: test.c
ifeq ($(OS),Linux)
	$(CC) $(CFLAGS) test.c -o test.o -lm
else
	$(CC) $(CFLAGS) test.c -o test.o
endif

test.c: 
	checkmk clean_mode=1 tests/include.file tests/*.check > test.c 
	clang-format -i -style=google test.c


s21_math.a : s21_math.c
ifeq ($(OS),Linux)
	$(CC) -c $(CFLAGS) s21_math.c -lm
else
	$(CC) -c $(CFLAGS) s21_math.c
endif
	ar rc s21_math.a s21_math.o
gcov_report: test.c
	$(CC) -fprofile-arcs -ftest-coverage test.c s21_math.c  -o tests/gcov_report $(TEST_FLAGS)
	tests/./gcov_report
	lcov -t "test" -o tests/test.info -c -d .
	genhtml -o report tests/test.info

open:
ifeq ($(OS),Darwin)
	xdg-open report/src/index.html
else
	open -a "Google Chrome" report/src/index.html
endif

clang:
	clang-format -n -style=google *.c *.h

clangI:
	clang-format -i -style=google *.c *.h

leak: test
ifeq ($(OS),Darwin)
	CK_FORK=no valgrind --leak-check=full -s --track-origins=yes --log-file=leak.log ./test
else
	CK_FORK=no valgrind --leak-check=full -s --track-origins=yes --log-file=leak.log ./test
endif	

clean:
	rm -rf *.o *.a *.out tests/*.info *.log *.html *.gc* test tests/gcov_report s21_math report test.c

rebuild: all
