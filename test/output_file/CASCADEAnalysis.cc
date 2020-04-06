#include "CASCADEAnalysis.hh"

CASCADEAnalysis::CASCADEAnalysis()
{
  fOutFile.open("example.txt");
}

CASCADEAnalysis::~CASCADEAnalysis()
{
  fOutFile.close();
}
