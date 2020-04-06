#ifndef CASCADEAnalysis_hh
#define CASCADEAnalysis_hh

#include <fstream>
#include <string>

class CASCADEAnalysis
{

  public:

    CASCADEAnalysis();
    ~CASCADEAnalysis();

    void writeLine(std::string str) { fOutFile << str << '\n'; }

  private:

    std::ofstream fOutFile;

};

#endif
