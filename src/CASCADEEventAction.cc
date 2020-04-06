
#include "CASCADEEventAction.hh"
#include "CASCADERunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CASCADEEventAction::CASCADEEventAction(CASCADERunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction),
  fEdep(0.0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CASCADEEventAction::~CASCADEEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADEEventAction::BeginOfEventAction(const G4Event*)
{
  fEdep = 0.0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADEEventAction::EndOfEventAction(const G4Event*)
{
  fRunAction->AddEdep(fEdep);
  G4cout << fEdep << G4endl;
}
