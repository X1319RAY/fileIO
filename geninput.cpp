#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	using namespace std;
	
	srand((unsigned) time(NULL));
	
	ofstream out("input.txt", ios::out);
	
	out << "ant: " << rand() % 'a' << endl;
	out << "buffalo: " << rand() % 'b' << endl;
	out << "cat: " << rand() % 'c' << endl;
	out << "dog: " << rand() % 'd' << endl;
	
	out.close();
	
	return 0;
}
