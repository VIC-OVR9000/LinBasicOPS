
#include <iostream>
#include <vector>

using namespace std;

#include "BasisVCTR.h";
#include "BasicOPS_0.h"




int main() { // vectors are coded in MATRIX FORM... MATRICES appear in matrix notation


	//trial();
	//BASE_transformation();

	
	

	/*
	BasisVCTR x({ 1,1,1,1,1,1,1,1,1});
		double m = MAGNITUDE(x);

		cout << "\n\n"<<m << "\n\n\n";

		*/

	
	vector<vector<double>> A=
	
	{

		{1,0,0},
		{0,1,1},
		{1,0,1}

	};//ENDOF A
	cout << endl;
	PrintVCTR(A);
		cout << endl;
		vector<vector<double>> T = TRANSFORM(A);


		for (int i = 0; i < A.size(); i++) {
		
			for (int j = 0; j < A[0].size(); j++) {
			
				cout << T[i][j] << ",";

			}//ENDOF 'j'
			cout << endl;
		
		}//ENDOF 'i'


		cout << "\n\n\n\n\n\n";

		cout << "CONSTRUCT X\n";
		vector<vector<double>> X = Construct_MATRIX();
		cout << "CONSTRUCT Y\n";
		vector<vector<double>> Y = Construct_MATRIX();


		cout << "XY =\n ";
		MATRIX_PRODUCT(X, Y);
		cout << "\n\n";
		cout << "YX =\n ";
		MATRIX_PRODUCT(Y, X);

}//ENDOF main()

