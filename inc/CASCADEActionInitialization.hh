#ifndef CASCADEActionInitialization_hh
#define CASCADEActionInitialization_hh

#include "G4VUserActionInitialization.hh"

class CASCADEActionInitialization : public G4VUserActionInitialization
{
  public:
    CASCADEActionInitialization();
    virtual ~CASCADEActionInitialization();

    virtual void Build() const;
};


#endif
