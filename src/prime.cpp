#include "colors.h" //used for the colors. Works on linux, I do not know about other operating systems.
#include <cstdint> //for uint64_t
#include <iostream> //for cout
#include <vector> //for vector
#include <cmath> //for sqrt

/*
This program calculates the first X primes (numofprimes) and then prints out the statistics on it. 

g++ prime.cpp -o out.o -std=c++14

is the command I use to compule, using gcc 5.4.0 20160609 for ubuntu.

if anyone knows a way to include partial libraries without including the entire thing than please
tell me. I do not believe that that works in c++ though.
*/

using namespace std; //I m only using the stantard namespace so there is no chance of a namespace clash.

vector<uint64_t> primes;

void print_vec(vector<auto>& vec){
	//this function is used to test to make sure the vector was actually filling with the values. 
	//I had a few issues at first that I didn't know why they were happening. 
	//when there are 50 or more items this function works but it takes up a lot of space.
	for(int i = 0; i<vec.size(); i++){
		cout << vec[i] << " ";
		cout.flush(); 
		//problems kept arising with cout and I found that if I kept a cout.flush() after each output
		//the problem would go away.
	}
}

void init(uint64_t a){
	primes.push_back(a);
	//this function used to contain a lot more. I have since reduced it to just this as it was mostly debugging stuff.
	//could probably live without the function but what is the worst to come from keeping it.
} 
/**/
int check_if_prime(uint64_t t, vector<auto>& vec){
	for(int it = 0; it<vec.size(); it++){
		if(sqrt(t)<vec[it]){ //this line changed the time to calculate the first million from nearly 40 minutes to less than 1 minute. 
			return 1;
		}else if(t%vec[it]==0){ //it used to just contain this which meant it would itterate throuh every prime, even if they were too big.
			return 0;
		}
	}
	return 1;
}
/**/

/* original version, quite slow in comparison. 
int check_if_prime(uint64_t t, vector<auto>& vec){
	for(int it = 0; it<vec.size(); it++){
		if(t%vec[it]==0){
			return 0;
		}
	}
	return 1;
}
/**/
int get_end(int ending, vector<auto>& vec){ //counts the number of digits 
	int counter = 0;
	for(uint64_t i = 0; i<vec.size(); i++){
		if((int)vec[i]%10==ending){
			counter++;
		}
	}
	return counter;
}	//this is used so I don't have to add logic in to add number of primes to each number.





//do_math is for finding the statistics of the primes that were looked at in this scope.
int do_math(vector<auto>& vals, vector<auto>& vec){ 
	int size = vec.size();
	if(vals[0]+vals[1]+vals[2]+vals[3]+vals[4]+vals[5]!=size){
		cerr << endl << errr << "Error, improper sizing constraints." << endl;
		cerr << (vals[0]+vals[1]+vals[2]+vals[3]+vals[4]+vals[5]) << " to size of " << size << endl;
		return 0; //returns out because a problem happened somewhere.
	}
	double ratios[6];
	ratios[0] = (double)vals[0]/(double)size;	
	ratios[1] = (double)vals[1]/(double)size;	
	ratios[2] = (double)vals[2]/(double)size;	
	ratios[3] = (double)vals[3]/(double)size;	
	ratios[4] = (double)vals[4]/(double)size;	
	ratios[5] = (double)vals[5]/(double)size;	
	cout << white <<endl;
	cout << "Primes ending in 1 are equal to: " << blue << ratios[0]*100 << white << "%, or a total of " << vals[0] << endl;
	cout << "Primes ending in 2 are equal to: " << blue << ratios[1]*100 << white << "%, or a total of " << vals[1] << endl;
	cout << "Primes ending in 3 are equal to: " << blue << ratios[2]*100 << white << "%, or a total of " << vals[2] << endl;
	cout << "Primes ending in 5 are equal to: " << blue << ratios[3]*100 << white << "%, or a total of " << vals[3] << endl;
	cout << "Primes ending in 7 are equal to: " << blue << ratios[4]*100 << white << "%, or a total of " << vals[4] << endl;
	cout << "Primes ending in 9 are equal to: " << blue << ratios[5]*100 << white << "%, or a total of " << vals[5] << endl;

	return 0;
}









int main(int argc, char* argv[]){
	int numofprimes = atoi(argv[1]);  //this allows for a person to declare number of primes before they want to look at.
	cout.flush(); //again flushes the stream
	int size = 1; //sets the size to 1 initially because we are going to manually add 2.
	init(2); //manually adding 2.
	for(uint64_t i = 3; size<numofprimes; i++){
		if(check_if_prime(i, primes)){
			init(i);			size++;
			if(size%1000000==0){
				cout << red << ".";
				cout.flush();
			} else if(size%100000==0){
				cout << blue << "."; 
				cout.flush();
			} else if(size%10000==0){
				cout << green << ".";
				cout.flush();
			}
		}
	}
	cout << endl;
	vector<int> values;
	//these lines are quite archaic but they work. I thought of putting into  for loop but couldn't figure ut a good way to do it without it taking more lines.
	values.push_back(get_end(1, primes));
	values.push_back(get_end(2, primes));
	values.push_back(get_end(3, primes));
	values.push_back(get_end(5, primes));
	values.push_back(get_end(7, primes));
	values.push_back(get_end(9, primes));

	do_math(values, primes); 
	
	//9223372036854775807 is the largest 64 bit integer.
	
	return 0;
}
