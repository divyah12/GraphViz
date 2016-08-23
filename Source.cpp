/*
Basically, This program randomly grenerates a Two-Dimensional Array
with the range of 0-4(exclusive). This generated Array is written to 
a dot file(Pgraphfile.dot) in the format that GraphViz can read, so to 
create a digraph. There's no console output, since the matrix is printed 
in the file itself.
I have referred to the documnet given in class for file write and
stackoverflow for syntax only.
*/
#include <iostream>
#include <fstream>
using namespace std;
int n=4;


int main()
{
	ofstream outfile("Pgraphfile.dot");
	int A[4][4];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				A[i][j] = 0;
			}
			else
			{
				A[i][j] = rand() % 3;
			}
		}
	}
		
	outfile << "//CMPS 5443" << endl;
	outfile << "//The adjacency Matrix is as below" << endl;
		//print 2D-Array
	for (int i = 0; i < n; ++i)
	{
		outfile << "//";
		for (int j = 0; j < n; ++j)
		{
			outfile << A[i][j] << ' ';
		}
		outfile << endl;
	}

	outfile << "digraph g {" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(A[i][j]!=0)
			outfile <<i<<" -> "<<j<<" [label = "<< A[i][j]<<"] " << endl;
		}
		
	}
	
	outfile << "}" << endl;
	outfile.close();
	system("pause");
	return 0;

}
