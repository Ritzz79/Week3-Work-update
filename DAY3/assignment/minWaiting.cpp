// C++ program for finding minimum waiting time
// This problem is solved by using the shortest job first algorithm 
// which is used in process shceduling in operating system.
#include <iostream>
using namespace std;
int mat[10][5];

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Sorts the customers according to the time they ordered the pan
void arrangeArrival(int num, int mat[][5])
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mat[j][0] > mat[j + 1][0]) {
				for (int k = 0; k < 4; k++) {
					swap(mat[j][k], mat[j + 1][k]);
				}
			}
		}
	}
}

// Find the minimum time for which each customer needs to wait
void completionTime(int num, int mat[][5])
{
	int temp, val;
	mat[0][2] = mat[0][0] + mat[0][1];	// Finish time for 1st customer
	mat[0][4] = mat[0][2] - mat[0][0];	// waiting time for 1st person
	mat[0][3] = mat[0][4] - mat[0][1];	

	// It takes care that whichever customer's pan takes least time to be cooked, gets the first chance
	for (int i = 1; i < num; i++) {
		temp = mat[i - 1][2];
		int low = mat[i][1];
		for (int j = i; j < num; j++) {
			if (temp >= mat[j][0] && low >= mat[j][1]) {
				low = mat[j][1];
				val = j;
			}
		}
		mat[val][2] = temp + mat[val][1];
		mat[val][4] = mat[val][2] - mat[val][0];
		mat[val][3] = mat[val][4] - mat[val][1];
		for (int k = 0; k < 5; k++) {
			swap(mat[val][k], mat[i][k]);
		}
	}
}

int main()
{
	int num;

	cin >> num; //number of process 
    
	for (int i = 0; i < num; i++) {
		cin >> mat[i][0];	//time customer ordered the pan and 
		cin >> mat[i][1];	//time to cook the pan
	}

	arrangeArrival(num, mat);   //Sorts the customers according to the time they ordered the pan
	completionTime(num, mat);	// Find the minimum time for which each customer needs to wait

	// Calculating the average of the waiting time
	int awt=0;
	for(int i=0; i<num; i++)
	    awt += mat[i][4];

	awt /= num;
	cout<<endl<<awt;

	return 0;
}
