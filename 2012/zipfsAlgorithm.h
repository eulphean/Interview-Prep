/*
	Program to illustrate Zipf's algorithm for song selection
*/

#include <fstream>
#include <iostream>

using namespace std;

struct Song {

	// Song name
	char *string;
	// Actual total plays of the song
	int f; 
};

int main (int argc, char * argv[]) {
	
	char * filename = argv[1];
	
	cout << filename;
	
	return 0;
}
	
	