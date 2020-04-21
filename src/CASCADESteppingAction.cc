#include "CASCADESteppingAction.hh"
#include "CASCADEEventAction.hh"
#include "CASCADEDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//
CASCADESteppingAction::CASCADESteppingAction(CASCADEEventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

CASCADESteppingAction::~CASCADESteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void CASCADESteppingAction::UserSteppingAction(const G4Step* step)
{
  // get the pointer to the scoring volume (target)
  if (!fScoringVolume) {
    const CASCADEDetectorConstruction* detectorConstruction
      = static_cast<const CASCADEDetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();
  }

  // get volume of the current step
  G4LogicalVolume* volume
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();

  // check to see if we are not in the scoring volume, if so, return
  if (volume != fScoringVolume) return;

  // otherwise, we are in the scoring energy, so add energy deposited in this
  // step to the cummulative sum in the event
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);
}
