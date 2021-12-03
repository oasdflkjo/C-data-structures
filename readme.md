![image](https://user-images.githubusercontent.com/47799698/144667788-dd871c69-e252-420f-817f-0036e68fc52d.png)

**Readme**

Algo drills on basic datatypes on c language

TODO
- linked list
- queue
- hash table
- tree
- heap

Notes on gtest

clone gtest

`git clone https://github.com/google/googletest.git`

Create environment variable that is pointing to directory where you have gtest - framework

`export GTEST_DIR=~/googletest/googletest`

`mkdir test_dir`

in this directory Compile the testing environment

`g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc`

`ar -rv libgtest.a gtest-all.o`

makefile for this

`g++ -isystem ${GTEST_DIR}/include -pthread unit_test_case.c code_to_be_tested.c Gtest_main.c libgtest.a -o my_test`
