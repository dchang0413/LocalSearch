all : sog_test greedy sa

sog_test : sog_test.cpp
	g++ sog_test.cpp SumofGaussians.cpp -o sog_test


greedy : greedy.cpp
	g++ greedy.cpp SumofGaussians.cpp -o greedy

sa : sa.cpp
	g++ sa.cpp SumofGaussians.cpp -o sa
