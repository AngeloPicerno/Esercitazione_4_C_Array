#pragma once
#include <iostream>


using namespace std;


bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int& S,
                   double*& w,
                   double*& r);

double RateOfReturn(const size_t& n,
                    const double*const& w,
                    const double*const& r);

double FinalValue(const double& rate,
                 const unsigned int& S);

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  unsigned int& S,
                  const double*const& w,
                  const double*const& r,
                  const double& rateOFreturn,
                  const double finalvalue);


string ArrayToString(const size_t& n,
                     const double* const& v);
