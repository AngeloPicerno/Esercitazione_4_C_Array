#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;
bool ImportVectors(const string& inputFilePath,
                        size_t& n,
                        unsigned int& S,
                        double*& w,
                        double*& r)
{
    ifstream file;
    file.open(inputFilePath);
    if (file.fail())
    {
        cerr<<"file open failed"<<endl;
        return false;

    }


    char c;
    string line;
    getline(file,line);
    istringstream ConvertS;
    ConvertS.str(line);
    for(unsigned int i=0;i<2;i++){
       ConvertS>>c;

    }
    ConvertS>>S;


    getline(file,line);
    istringstream ConvertN;
    ConvertN.str(line);
    for(unsigned int i=0;i<2;i++){
        ConvertN>>c;

    }
    ConvertN>>n;



    getline(file,line);

    //istringstream Convert;
    w=new double[n];
    r=new double[n];
    int i =0;
    while(!file.eof())
    {
        getline(file,line);
        istringstream Convert;
        Convert.str(line);
        Convert>>w[i];
        Convert>>c;
        Convert>>r[i];
        i++;


    }
    file.close();
    return true;

 }

double RateOfReturn(const size_t& n,
                    const double*const& w,
                    const double*const& r)
 {
    double rateOfreturn=0;
     for(unsigned int i=0;i<n;i++)
       rateOfreturn += w[i]*r[i];
     return rateOfreturn;

 }

 double FinalValue(const double& rate,
                   const unsigned int& S)
 {
     double SumValue=(1+rate)*S;
     return SumValue;
 }



 bool ExportResult(const string& outputFilePath,
                   const size_t& n,
                   unsigned int& S,
                   const double*const& w,
                   const double*const& r,
                   const double& rateOFreturn,
                   const double finalvalue)

 {
     ofstream file;
     file.open(outputFilePath);

     if (file.fail())
     {
         cerr<<"file open failed"<<endl;
         return false;
     }
     file<<" S="<<fixed<<setprecision(2)<<S<<","<<"n="<<n<<endl;
     file<<"[";
     for (unsigned int i = 0; i < n; i++)
         file<< (i != 0 ? " " : "")<< w[i];
     file<<"]";
     file<<endl;
     file<<"[";


     for (unsigned int i = 0; i < n; i++)
         file<< (i != 0 ? " " : "")<< r[i];
     file<<"]";
     file<<endl;

     file<<"Rate of return of the portfolio:"<<fixed<<setprecision(4)<<rateOFreturn<<endl;
     file<<"V:"<<fixed<<setprecision(2)<<finalvalue;


     file.close();
     return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}












