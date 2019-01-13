#include <iostream>
#include <cstdlib>

#include "SumofGaussians.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	int seed = atoi(argv[1]);
	int dims = atoi(argv[2]);
	int ncenters = atoi(argv[3]);

	srand(seed);
	SumofGaussians sog(dims,ncenters);

	int count = 0;
	double input[dims];
	double temp[dims];
	double dz[dims];
	bool peak[dims] = {false};
	bool complete = false;

	for(int i = 0; i < dims; i++)
	{
		input[i] = getRandom()*10;
	}

	do{
		sog.deriv(input,dz);
		for(int i = 0; i < dims; i++)
		{
			if(not peak[i])
			{
				for(int j = 0; j < dims; j++)
				{
					temp[j] = input[j] + 0.01*dz[j];
				}
				double diff = sog.eval(input) - sog.eval(temp);
				if(diff < 0.00000001 && diff > -0.00000001)
				{
					peak[i] = true;
				}
				else
				{
					for(int j = 0; j < dims; j++)
					{
						input[j] = temp[j];
					}
				}
				for(int k = 0; k < dims; k++)
				{
					cout << input[k] << " ";
				}
				cout << sog.eval(input) << endl;
			}
		}
		count = 0;
		for(int i = 0; i < dims; i++)
		{
			if(peak[i])
			{
				count++;
			}
		}
		if(count == dims)
		{
			complete = true;
		}
	}while(not complete);

	for(int i = 0; i < dims; i++)
	{
		cout << input[i] << " ";
	}
	cout << sog.eval(input) << endl;
	return 0;
}