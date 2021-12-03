# make  - to compile normal run
# make test - to compile for unit testing 

GTEST_DIR=~/googletest/googletest

COPTS=-Wall -funsigned-char  -fpermissive
LDFLAGS=

PROJ=code_to_be_tested

######### Main targets ##########
release: main.o $(PROJ).o
	gcc main.o $(PROJ).o -o release $(LDFLAGS)

test: Gtest_main.o test_case.o $(PROJ)_test.o libgtest.a
	g++  $(LDFLAGS) -I $(GTEST_DIR)/include -pthread $(PROJ)_test.o test_case.o Gtest_main.o libgtest.a -o test

########## Normal - Release ###########

$(PROJ).o: $(PROJ).c 
	gcc  -c $(PROJ).c

main.o: main.c my_math.h.h
	gcc -c main.c

########## Unit test - test ########

Gtest_main.o: Gtest_main.c
	g++ -c -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) Gtest_main.c

$(PROJ)_test.o: $(PROJ).c 
	g++  -c $(PROJ).c -o $(PROJ)_test.o

test_case.o: test_case.c
	g++ -c -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) $(COPTS) test_case.c

########## Google Test framework ############
libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

########## Clean ######################
clean:
	rm -f *.o

