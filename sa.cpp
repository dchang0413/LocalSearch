#include <iostream>
#include <cstdlib>
#include <math.h>

#include "SumofGaussians.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	int seed = atoi(argv[1]);
	int dims = atoi(argv[2]);
	int ncenters = atoi(argv[3]);

	srand(seed);
	SumofGaussians sog(dims,ncenters);

	double input[dims];
	double temp[dims];
	double dz[dims];
	bool peak[dims] = {false};
	bool complete = false;

	for(int i = 0; i < dims; i++)
	{
		input[i] = getRandom();
	}

	for(double t = 100000; t > 0; t--)
	{
		for(int i = 0; i < dims; i++)
		{
			temp[i] = input[i] + 0.02*getRandom() - 0.01;
		}
		if(sog.eval(temp) > sog.eval(input))
		{
			for(int i = 0; i < dims; i++)
			{
				input[i] = temp[i];
				cout << input[i] << " ";
			}
			cout << sog.eval(input) << endl;
		}
		else
		{
			double dice = (rand()%100)+1;
			double chanceOfAccept = exp((sog.eval(temp) - sog.eval(input))/t);
			if(chanceOfAccept >= dice)
			{
				for(int i = 0; i < dims; i++)
				{
					input[i] = temp[i];
					cout << input[i] << " ";
				}
				cout << sog.eval(input) << endl;
			}
		}
	}
	
	for(int i = 0; i < dims; i++)
	{
		cout << input[i] << " ";
	}
	cout << sog.eval(input) << endl;
	return 0;
}