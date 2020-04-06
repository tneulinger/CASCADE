#ifndef CASCADESteppingAction_hh
#define CASCADESteppingAction_hh

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

class CASCADEEventAction;
class G4LogicalVolume;

class CASCADESteppingAction : public G4UserSteppingAction
{

  public:
    CASCADESteppingAction(CASCADEEventAction* eventAction);
    virtual ~CASCADESteppingAction();

    // method from base class 
    virtual void UserSteppingAction(const G4Step*);

  private:
    CASCADEEventAction* fEventAction;
    G4LogicalVolume*    fScoringVolume;

};

#endif
