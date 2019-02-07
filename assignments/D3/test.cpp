#include <iostream>
#include <string>
using namespace std;
int main()
{
    int nSteps(11);
    double xmax(3.14);
    double xmin(0);
    
    double h = (xmax - xmin)/(nSteps-1);//find the h that we need for nSteps
    bool first(true);
    
    // dynamically allocate memory of size sz
	double* dyna = new double(static_cast<double>(nSteps));

	// assign values to allocated memory
	for (int i = 0; i < 1; i++){
		for (int j = 0; j < nSteps; j++){
                if(first){
			        *(dyna + i + j) = xmin;
                    first = false;
                }
                else{
                    xmin = xmin + h;
                    *(dyna + i + j) = xmin;
                }
        }
    }
    
    cout << "terminated normally" <<endl;
    
    //print allocated memory
    for( int j = 0; j<nSteps; j++){
        cout << *(dyna + 0 +j) << " ";
    }
    cout << endl;
    
	// deallocate memory
    delete[] dyna;

	return 0;
}