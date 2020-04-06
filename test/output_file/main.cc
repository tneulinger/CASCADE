#include <string>

#include "CASCADEAnalysis.hh"

int main ()
{

  CASCADEAnalysis* a = new CASCADEAnalysis;

  std::string lineToWrite{"This is a line."};
  a->writeLine(lineToWrite);

  return 0;
}
