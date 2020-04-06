#ifndef CASCADEEventAction_hh
#define CASCADEEventAction_hh

#include "G4UserEventAction.hh"
#include "globals.hh"

class CASCADERunAction;

class CASCADEEventAction : public G4UserEventAction
{

  public:
    CASCADEEventAction(CASCADERunAction* runAction);
    virtual ~CASCADEEventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void   EndOfEventAction(const G4Event* event);

    void AddEdep(G4double edep) { fEdep += edep; }

  private:
    CASCADERunAction* fRunAction;
    G4double          fEdep;

};

#endif
