compile: 
	clang++ -g -std=c++14 ./Code/*.cpp -o output
automated:
	clang++ -g -std=c++14 ./compilecode/automated.cpp -o auto_out
	./auto_out