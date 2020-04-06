#ifndef CASCADERunAction_hh
#define CASCADERunAction_hh

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class CASCADERunAction : public G4UserRunAction
{
  public:
    CASCADERunAction();
    virtual ~CASCADERunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);

    void AddEdep(G4double edep);

  private:
    G4double fEdep;
};


#endif
