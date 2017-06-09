all:
	clang++ -c -fPIC -Wall -Wextra  -Werror  test.cpp
	clang++ -shared -fPIC -o libtest.so test.o
	clang++ main.cpp
