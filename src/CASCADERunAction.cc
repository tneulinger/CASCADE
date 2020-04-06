#include "CASCADERunAction.hh"

#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CASCADERunAction::CASCADERunAction()
: G4UserRunAction(),
  fEdep(0.0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CASCADERunAction::~CASCADERunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADERunAction::BeginOfRunAction(const G4Run*)
{
  fEdep = 0.0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADERunAction::EndOfRunAction(const G4Run*)
{
  G4cout << " =================== END OF RUN =================== " << G4endl;
  G4cout << " Total energy deposited = " << fEdep << "." << G4endl;
  G4cout << " ================================================== " << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADERunAction::AddEdep(G4double edep)
{
  fEdep += edep;
}
