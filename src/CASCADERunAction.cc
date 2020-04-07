#include "globals.hh"

#include "G4SystemOfUnits.hh"

#include "Analysis.hh"
#include "CASCADERunAction.hh"

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

  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // create histogram
  analysisManager->CreateH1("0","Edep in gas", 100, 0.0, 6.0*CLHEP::MeV);

  // open file
  G4String fileName = "ALPHA_ENERGY";
  analysisManager->OpenFile(fileName);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADERunAction::EndOfRunAction(const G4Run*)
{
  // G4cout << " =================== END OF RUN =================== " << G4endl;
  // G4cout << " Total energy deposited = " << fEdep << "." << G4endl;
  // G4cout << " ================================================== " << G4endl;

  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // save histogram and write file
  analysisManager->Write();
  analysisManager->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADERunAction::AddEdep(G4double edep)
{
  fEdep += edep;
}
