/*
	Program to reverse a positive binary number
	
	13 (1101) - 11 (1011)
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cstring>

using namespace std;

int main () {
	
	// Getting the input from stdin
	int mynumber;
	cin >> mynumber;
	
	if (mynumber < 1 || mynumber > 1000000000){
		cerr << "ERROR";
		exit (0);
	}
		
	
	int maxcounter = 0;
	int mynum = 0;
	int newnumber = 0;
	
	while (mynum!=mynumber){
		int a = pow (2, maxcounter);
		mynum = mynum + ((mynumber & a) >> maxcounter) * a;
		maxcounter++;
	}

	for (int i =1; i<=maxcounter; i++){
		int p = pow (2, (i-1));
		int a = ((mynumber & p) >> (i-1));
		newnumber = newnumber + (a << (maxcounter - (i)));
	}
	
	cout << newnumber;
	return 0;
}