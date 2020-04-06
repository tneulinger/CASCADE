#include "CASCADEActionInitialization.hh"
#include "CASCADEPrimaryGeneratorAction.hh"
#include "CASCADERunAction.hh"
#include "CASCADEEventAction.hh"
#include "CASCADESteppingAction.hh"

// constructor
CASCADEActionInitialization::CASCADEActionInitialization()
  : G4VUserActionInitialization()
{
  //
}

// destructor
CASCADEActionInitialization::~CASCADEActionInitialization()
{
  //
}

void CASCADEActionInitialization::Build() const
{
  CASCADEPrimaryGeneratorAction* primaryAction = new CASCADEPrimaryGeneratorAction;
  SetUserAction(primaryAction);

  CASCADERunAction* runAction = new CASCADERunAction;
  SetUserAction(runAction);

  CASCADEEventAction* eventAction = new CASCADEEventAction(runAction);
  SetUserAction(eventAction);

  SetUserAction(new CASCADESteppingAction(eventAction));
}
