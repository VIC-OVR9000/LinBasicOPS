#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


/// include header files here
#include "BasicOPS_0.h"


int trial() {



	BasisVCTR X;//initializing to zero value per SOP
	X.setBasis();

	int size = X.getDIMENSION();
	//cout << size;


	BasisVCTR Y;
	Y.setBasis();


	double DOT = computeDOT(X, Y);
	cout << "\n\n" << "DOT RPODUCT = " << DOT << "\n\n";


	vector<double> CROSS = computeCROSS(X, Y);
	cout << "CROSS PRODUCT = ";
	cout << "[ ";
	for (int a = 0; a < CROSS.size(); a++) {
		if (a == CROSS.size() - 1) { cout << CROSS[a]; }
		else { cout << CROSS[a] << " , "; }

	}//ENODF for CROSS
	cout << "]";


	BasisVCTR cross(CROSS);
	double MAG = MAGNITUDE(cross);
	cout << "\nMAGNITUDE of the CROSS PRODUCT = " << MAG << endl;



	cout << "\n\n\n\n\n";
	return 0;
}//ENDOF trial()





void BASE_transformation_3D() {

	cout << "\n////////////////////\/COMPUTE 'V' in terms of STANDARD BASIS (i,j,k)\n/////////////////////////\n\n"<<
		"A(e1,e2,e3) = A :::: AV = b\n\n\n";

	/*
	BasisVCTR e1({ 1,0,0 });
	BasisVCTR e2({ 0,1,0 });
	BasisVCTR e3({ 0,0,1 });
	*/
	
	BasisVCTR e1;
	BasisVCTR e2;
	BasisVCTR e3;
	cout << "PROGRAM the vector 'e1'...\n\n";
	e1.setBasis();
	cout << "PROGRAM the vector 'e2'...\n\n";
	e2.setBasis();
	cout << "PROGRAM the vector 'e3'...\n\n";
	e3.setBasis();

	//BasisVCTR V({ 1,1,2 });
	cout << "PROGRAM the vector 'V'...\n\n";
	BasisVCTR V;//in basis reference
	V.setBasis();


	vector<double> b = (BASIS_VECTOR_PRODUCT_3D(e1, e2, e3, V));//V in standard basis : (A^T)V=b
	cout << "[";
	for (int i = 0; i < b.size(); i++) {
		if (i == b.size()-1){ cout << b[i] << " "; }
		else { cout << b[i] << " , "; }
	}
	cout << "]^T";
}//ENDOF base transformation



vector<vector<double>> ConstructBASIS_MAT() {

	int basis;
	int dimension;

	cout << " how many basis vectors...?\nENTER: "; cin >> basis; cout << "\n";
	cout << " ENTER dimensions for basis vectors...?\nENTER: "; cin >> dimension; cout << "\n";

	vector<vector<double>> A(dimension);
	//since the basis vectors are wriitne vertically in matrix form, the coded vector must have rows equal to dimension of basis vectors
	// 'n' are 'm' seem to be used in reverse, function still produces vertically aligned basis matrix

	for (int n = 0; n < basis; n++) {/// 'n' collumns

		for (int m = 0; m < dimension; m++) {/// 'm' rows

			cout << " ENTER x_" << m + 1 << " for basis_" << n + 1 << "\n";

			double ent;
			cin >> ent;
			A[n, m].push_back(ent);//m/n are swapped so, as to program vertically...

		}//ENDOF 'n'
	}//ENDOF 'm'


	/*
	vector < vector<double>> A =
	{ { 7, 8, 9},//A[0
	  { 4, 5, 6},//A[1
	  { 1, 2, 3}   };//A[1
	int dimension = A.size();
	*/



	for (int m = 0; m < A.size(); m++) {/// print by rows

		cout << "|";

		for (int n = 0; n < A[m].size(); n++) {// print each component in each row.


			if (n == basis - 1) { cout << A[m][n] << ' '; }
			else { cout << A[m][n] << ","; }


		}//ENDOF 'n'
		cout << "|\n";



	}//ENDOF 'm'


	return A;

}//ENDOF construct BASIS-MATRIX


vector<vector<double>> MATRIX_PRODUCT(vector<vector<double>> A, vector<vector<double>> B) {
	
	// compute AB matrices are programed in ROW/COLLUMN FORM!!!


	vector <vector<double>> result(A[0].size());

	if (A[0].size() != B.size()) { cout << " cannot compute matrix product for non-aligned grouping :: A(n) != B(m)"; }
	else {

		

		for (int q = 0; q < A.size(); q++) {

			
		
			for (int r = 0; r < B[q].size(); r++) {
				double sum = 0;
				
				
			
				for (int s = 0; s < A[q].size(); s++) {



					double arg = A[q][s] * B[s][r];

					sum += arg;
				
				
				}//ENDOF 's'
				
				cout << sum << " , ";
				result[r].push_back(sum);
				
			
			
			}//ENDOF 'r'
			cout << endl;
	
		}//ENDOF 'q'
	
	
	}//ENDOF 'else'

	return result;


}//endof AB

vector<vector<double>> TRANSFORM(vector<vector<double>> X) {

	int M = X[0].size();
	int N = X.size();//b/c we are swapping

	//swap row into collumns
	vector<vector<double>>B(N);

	for (int m = 0; m < N; m++) {
	
		for (int n = 0; n < M; n++) {
		
			B[n,m].push_back(X[n][m]);

		}//ENDOF 'n'
		
	}//ENDOF 'm'


	return B;

}//ENDOF TRANSFORM


vector<vector<double>> Construct_MATRIX() {
	int M;
	int N;


	cout << "HOW MANY Rows...?\nENTER(M):"; cin>> M;
	cout << "HOW MANY Collumns...?\nENTER(N):"; cin >> N;

	vector<vector<double>> MAT(M);

	for (int i = 0; i < M; i++) {
		cout<< "INPUT ROW: " << i << endl;
		for (int j = 0; j < N; j++) {
		
			cout << "COLLUMN: " << j << endl;
			double x;
			cin >> x;
			
				MAT[j,i].push_back(x);

			cout << endl;
		
		}//ENDOF 'j'
	
	}//ENDOF 'i'

	for (int i = 0; i < M;i++) {
		for (int j = 0; j < N; j++) {
		
			cout << MAT[i][j] << ",";
		}
		cout << endl;
	}

	return MAT;
}//ENDOF CONstruct MATRIX

void PrintVCTR(vector<vector<double>> V) {

	int M = V.size();

	for (int i = 0; i < M; i++) {
	
		for (int j = 0; j < V[i].size(); j++) {
			cout << V[i][j] << " , ";
		
		}
		cout << endl;
	
	}//ENDOF 'i'


}