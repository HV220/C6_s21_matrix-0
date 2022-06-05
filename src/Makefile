.PHONY: all clean test s21_matrix.a check rebuild open gcov_report
g = gcc
flags = -Wall -Wextra -Werror -std=c11
LINUX = -lrt -lpthread -lm -lsubunit
LIBS = -lcheck
LFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)

all: clean s21_matrix.a test

s21_matrix: s21_matrix.c
	$(g) -c s21_matrix.c -o s21_matrix.o

s21_matrix.a: s21_matrix
	ar rcs s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a

test: s21_matrix.a
ifeq ($(OS), Darwin)
		$(g) $(flags) s21_test_matrix.c s21_matrix.a -o test.out $(LIBS)
		./test.out
else
		$(g) $(flags) s21_test_matrix.c s21_matrix.a -o test.out $(LIBS) $(LINUX)
		./test.out
endif
gcov_files:
ifeq ($(OS), Darwin)
		$(g) $(flags) $(LFLAGS) s21_test_matrix.c s21_matrix.c -o test.out $(LIBS)
else
		$(g) $(flags) $(LFLAGS) s21_test_matrix.c s21_matrix.c -o test.out $(LIBS) $(LINUX)
endif

gcov_report: gcov_files
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

open: 
ifeq ($(OS), Darwin)
		open report/index.html
else
		xdg-open report/index.html
endif
	
check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test.out
else
	valgrind ./test.out --leak-check=full
endif
	make clean

clean:
	rm -rf *.gc* *.o *.a *.out *.info test.out
	rm -rf report

rebuild: clean all