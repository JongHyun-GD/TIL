GTEST_DIR=gtest/googletest

all:
	c++ -o ex00_test ex00_test.cc ex00/megaphone.cpp

test:
	c++ -o ex00_test ex00_test.cc ./ex00/megaphone.cpp -isystem ${GTEST_DIR}/googletest/include -L${GTEST_DIR}/build/lib -pthread -lgtest -lgtest_main -std=c++11
	./ex00_test -Iex00_test.h
