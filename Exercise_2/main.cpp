#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include<iomanip>



using namespace std;


int main()
{
    string inputFileName="./data.csv";
    size_t n=0;
    unsigned int S=0.0;
    double* w= nullptr;
    double*r=nullptr;

    if(!ImportVectors(inputFileName,n,S,w,r))
    {
        cerr<<"Something goes wrong with import"<<endl;
        return -1;
    }
    else
        cout<<"Import successful:n="<<n<<" "<<"S="<<fixed<<setprecision(2)<<S<<" "<<"w="<<ArrayToString(n,w)<<" "<<"r="<<ArrayToString(n,r)<<endl;


    double rateofreturn=RateOfReturn(n,w,r);
    cout<<"rate of return="<<fixed<<setprecision(4)<<rateofreturn<<endl;

    double sumvalue= FinalValue(rateofreturn,S);
    cout<<"V="<<fixed<<setprecision(2)<<sumvalue<<endl;


    string outputFileName="result.txt";
    if (!ExportResult(outputFileName, n, S, w,r,rateofreturn,sumvalue))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;
    delete[] w;
    delete[] r;




   return 0;
}

