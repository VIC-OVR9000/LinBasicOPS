#pragma once
class BasisVCTR
{

private:

	int DIMENSION;
	
	vector<double> BASIS;
	vector<BasisVCTR> ND_SPACE;


public:
	
	BasisVCTR();
	BasisVCTR( vector<double> base);
	void setBasis();//used for larger ND basis vectors
	int getDIMENSION();//retriece dimension of basis
	void setDIMENSION(int);//reset dimension of basis
	vector<double> getBASIS();//retrieve vector 'array'


};//ENDOF class


double computeDOT(BasisVCTR& A, BasisVCTR& B);
vector<double> computeCROSS(BasisVCTR& A, BasisVCTR& B);
double MAGNITUDE(BasisVCTR &A);
vector<double> BASIS_VECTOR_PRODUCT_3D(BasisVCTR& X, BasisVCTR& Y, BasisVCTR& Z, BasisVCTR & V);
