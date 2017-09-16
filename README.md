# Prime-Calculation
A program that will calculate the first N primes (requiring some input) and provide some statistics on those primes.

To compile: g++ prime.cpp -o out.o -std=c++14
using gcc 5.4.0 20160609 for ubuntu.
To Run: ./out.o [number]

# About
This program requires 1 argument to run, a number. for example, if I compiled as
g++ prime.cpp -o prm -std=c++14
then to run it and have it calculate 1 million primes I would use the command
./prm 1000000

# Output
Every green '.' signifies 10,000 prime numbers have been calculated. Every blue '.' is 100,000 primes calculated
and every red '.' signifies 1,000,000 primes output. Once it is complete in calculating the number of primes you
requested it will break down the primes into their endings. For instance in the first 10 primes are as follows: 
2, 3, 5, 7, 11, 13, 17, 19, 23, 29
So the breakdown of their endings is
1: 1 10%
2: 1 10%
3: 3 30%
5: 1 10%
7: 2 20%
9: 2 20%
for a total of 10. 


# Futre Features
Adding consecutive evaluations, so finding the proportionality of a prime ending in N being followed by a prime ending in Y
for instance, 13 ends in 3, and the next prime ends in 7. 

Adding the largest difference between consecutive primes. An example for the first 10 primes would be the difference between 23 and 29 being 6, with the previous largest difference being held by 7 and 11 for 4. If there are primes that hold a difference of equal proportion to primes previously coveredthen I will ignore them. 

Making it so that it will check to see if the next prime it is checking is greater than the number in question divided by prime[n-1] (the previous prime) because if it is than it would require a prime smaller than it to multiply by to get to the number in question. 

# Notice
Do not pick super large numbers. Although I have sped this progam up immensly since its first version (the first time it ran I sat there for nearly 20 minutes calculating the first million, now it takes less than 1 minute to do that calculation) Pick what your computer can handle. If there are any methods that you know of that can increase the speed more than please tell me, I would be happy to attempt to make this faster.

# Explaining how it calculates primes

So this program will determine if a number is a prime by checking to see if any of the primes in a list (vector/array) of primes will evenly divide into it. If none of them can then it is added to the list as a prime. Now, to shorten the number of primes we are searching for we will first check to see if the primes that you are dividing the number by are less than that numbers square root, if they arent than the number is added to the list of primes.
