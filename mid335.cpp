
//Fernando Villarreal
//Midterm 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
#define MAX_SIZE  200;
//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4
typedef enum {
	C = 1,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	END = B,
	HALF_STEPS_PER_OCTAVE = B 
	//adding note Z
	
} note_t;

//function prototypes
float testFunction();
double freq(note_t note, int octave_delta);


int main(int argc, char *argv[])
{
	note_t note;
	int octave_delta;

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
		return 0;
	}
	//
	note = (note_t)(toupper(argv[1][0]) - 64);
	switch(toupper(argv[1][0])) {
		case 'A': note = A; break;
		case 'B': note = B; break;
		case 'C': note = C; break;
		case 'D': note = D; break;
		case 'E': note = E; break;
		case 'F': note = F; break;
		//adding note Z and is equal to O to upper
		//case 'Z': note = O; break;
	}
	//You may call your unit test here...
	//test function
	testFunction();
	if (note > END) {
		cout << "Invalid note!" << endl;
		return 1;
	}
	octave_delta = atoi(argv[2]);
	cout << HALF_STEPS_PER_OCTAVE << endl;
	cout << freq(note, octave_delta) << endl;
	return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
	double freq;
	double factor;
	double a;
	int n;
	int octave = octave_delta - F0_octave;

	a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
	n = note - F0_note;
	freq = F0 * pow(a, (double)n);
	factor = pow(2.0, (double)octave);
	freq = freq * factor;
	return freq;
}

float testFunction() {
	
	//holding data array
	//char data[MAX_SIZE];
	//using a string array	
	//open file for reading
	char var[100];
	ifstream infile;	
	infile.open("data.txt");	
	for(int i=0; i<100; i++) {
 
	infile >> var[i];
	}
	while(infile) {
	cout << "For debugging purposes "<< var << endl;
	break;
	}

		
	cout<<fixed<<showpoint<<setprecision(2)<<endl;
	cout<<"note  "<<"octave  "<< "value  "<<"diff  "<<endl;	
	return 0;
}
