
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

#include "BasisVCTR.h"



/* ALL Basis VCTR variants MUST have DIMESNION and BASIS variable initialized...*/
BasisVCTR::BasisVCTR(){}
BasisVCTR::BasisVCTR(vector<double> base) {

	DIMENSION = base.size();
	BASIS = base;
	
}//ENDOF 


void BasisVCTR:: setBasis() {

	/*general approach to creating BasisVCTR object
	initalize object as zero value

	ex.

	BasisVCTR plane();
	plane.getBasis();

	or 

	BasisVCTR plane({1,2,3});

	this 'creates the basis vector object...

	set DIMENSION
	set BASIS variables of Object 
	
	*/

	int dimension;//size of vector

	double component_INPUT;//collect values for each component

	vector<double> basis_vctr;//form basis vector from componene_input

	cout << "set dimension of BASIS VECTOR...\nENTER HERE:"; cin >> dimension; cout << "\n\n";
	

	for (int a = 0; a < dimension; a++) {

		cout << "ENTER x_" << a + 1 << " component value: "; cin >> component_INPUT; cout << "\n";

		basis_vctr.push_back(component_INPUT);

	}//ENDOF for 'a'

	cout << "[ ";
	for (int a = 0; a < dimension; a++) {

		if(a == dimension-1) { cout << basis_vctr[a] << " "; }
		else cout  << basis_vctr[a] << " , ";


	}//ENDOF for 'a'
	cout << " ]";

	cout << "\n\n\n";

	BASIS = basis_vctr;
	DIMENSION = basis_vctr.size();

}//ENDOF set basis vector




int BasisVCTR::getDIMENSION() {

	
	return DIMENSION;
}//ENDOF get DIM



void BasisVCTR::setDIMENSION(int s) {
	DIMENSION = s;
	

}//ENDOF set DIM


vector<double> BasisVCTR::getBASIS() {


	return BASIS;

}//ENDOF getBASIS



double computeDOT(BasisVCTR & A, BasisVCTR & B) {

	vector<double> AA = A.getBASIS();
	vector<double> BB = B.getBASIS();


	double SUM = 0;
	if (AA.size() == BB.size()) {

		for (int d = 0; d < AA.size(); d++) {

			double prod = AA[d] * BB[d];

			SUM += prod;

		}//ENDOF for
	}//ENDOF if equal sizes
	else { cout << "\n\ncannot compute DOT PRODUCT for non-square Matrix\n\n"; }

	return SUM;



}//ENDOF DOT


vector<double> computeCROSS(BasisVCTR& A, BasisVCTR& B) {

	vector<double> AA = A.getBASIS();
	vector<double> BB = B.getBASIS();

	if (AA.size() != BB.size()) { cout << "\ncannot compute CROSS PRODUCT for a non square matrix...\n"; }
	else if (AA.size() != 3 || BB.size() != 3) { cout << "\ncannot compute CROSS PRODUCT for MATRICES of N!=M : != 3...\n"; }
	else {

		double i = (  AA[1] * BB[2]) - (AA[2] * BB[1] );
		double j = -(  AA[0] * BB[2] - AA[2] * BB[0]  );
		double k = AA[0] * BB[1] - AA[1] * BB[0];

		vector<double> CROSS = { i,j,k };
		return CROSS;
	}

}//ENDOF CROSS

double MAGNITUDE(BasisVCTR& A) {

	double MAG = 0;
	double magARG = 0;

	vector<double> AA = A.getBASIS();
	//if (AA.size() != 3) { cout << "\n\ncannot compute magnitude...not 3D\n"; return MAG; }
	//else {

	for (int i = 0; i < AA.size(); i++) {
	//double magARG = pow(AA[0], 2) + pow(AA[1], 2) + pow(AA[2], 2);

		double ARG = pow(AA[i], 2);
		magARG += ARG;
}//ENDOF 'for'

	MAG = sqrt(magARG);
	return MAG;
//}

}


vector<double> BASIS_VECTOR_PRODUCT_3D(BasisVCTR &X, BasisVCTR &Y, BasisVCTR &Z, BasisVCTR &V) {

	vector<double> B1 = X.getBASIS();
	vector<double> B2 = Y.getBASIS();
	vector<double> B3 = Z.getBASIS();



	vector<double> VV = V.getBASIS();//matrix being transformed into standard basis matrix
	vector<double> B;//resultant matrix in standard basis. a vector outside of the class BasisVCTR


	if ((VV.size() != B1.size()) || (VV.size() != B2.size()) || (VV.size() != B3.size()))
	{
		cout << "\ncannot compute MATRIX PRODUCT for mis-aligned product grouping :: V(n) != A(n)\n";
	}//ENDOF if non-square Matrix


	else {

	vector<vector<double>> A = {

		{B1[0],B2[0],B3[0]},//add A[0][0] * * *
		{B1[1],B2[1],B3[1]},//add * * * 
		{B1[2],B2[2],B3[2]} //add    * * * A[w][q]
								
								};//endof matrix A

		for (int w = 0; w < A.size(); w++) {
			double x = 0;
			double SUM = 0;
			for (int q = 0; q < A[w].size(); q++) {

				x = VV[q] * A[w][q];
				SUM += x;

			}//ENDOF 'q'
			B.push_back(SUM);
		}//ENDOF 'w'

	}

	return B;



}//ENDOF basis vector product
