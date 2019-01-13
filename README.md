# LocalSearch
Local search using greedy local search and simulated annealing for CSCI 4350 Introduction to Artificial Intelligence

Overview

Develop a software agent in C++ to find the maximum value of the Sum of Gaussians (SoG) function
Procedure

    Create a C++ program which uses greedy local search (gradient ascent) to obtain the maximum value of the SoG function, G(), in D dimensions (greedy.cpp)
        The program should take 3 command-line arguments [integer: random number seed, integer: number of dimensions (D) for the SoG function, integer: number of Gaussians (N) for the SoG function]
        The program should start in a random location X in the [0,10] D-cube, where X is a D-dimensional vector
        The program should use a step size of (0.01*dG(X)/dX) to perform gradient ascent
        The program should terminate when the value of the function no longer increases (within 1e-8 tolerance)
        The program should print the location (X) and SoG function value (G(X)) at each step (see requirements)
    Create a C++ program which uses simulated annealing (SA) to obtain the maximum value of the SoG function in D dimensions (sa.cpp)
        The program should take 3 command-line arguments [integer: random number seed, integer: number of dimensions for the SoG function, integer: number of Gaussians for the SoG function]
        The program should start in a random location X in the [0,10] D-cube, where X is a D-dimensional vector
        The program should create an annealing schedule for the termperature (T), and slowly lowering T over time
        On each iteration, the program should generate a new location Y = X + runif(-0.01,0.01), and choose to accept it or reject it based on the metropolis criterion:
            if G(Y) > G(X) then accept Y; otherwise accept Y with probability e^((G(Y)-G(X))/T) 
        The program should terminate at a maximum of 100000 iterations
