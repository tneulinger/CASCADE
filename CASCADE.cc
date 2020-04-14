#include "globals.hh"
#include "G4PhysListFactory.hh"
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "CASCADEActionInitialization.hh"
#include "CASCADEDetectorConstruction.hh"
#include "CASCADEPhysicsList.hh"

int main(int argc, char** argv)
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // 1. detect interactive or batch mode
  G4String macroFile = "";
  G4UIExecutive* uiExecutive = nullptr;
  if (argc==1)
  {
    // interactive mode
    uiExecutive = new G4UIExecutive(argc, argv);
  } else {
    // batch mode, load macro file
    macroFile = argv[1];
    G4cout << macroFile << G4endl;
  }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // 2. create run manager object and register detector, physics, and actions

  // run manager
  G4RunManager* runManager = new G4RunManager;

  // detector
  CASCADEDetectorConstruction* detector = new CASCADEDetectorConstruction;
  runManager->SetUserInitialization( detector );

  // physics list
  // G4String physListName = "FTFP_BERT_EMZ";
  // G4String physListName = "QGSP_BIC";
  // G4String physListName = "LBE";
  // G4PhysListFactory physListFactory;
  // G4VModularPhysicsList* physList
   // = physListFactory.GetReferencePhysList( physListName );
  // runManager->SetUserInitialization( physList );
  runManager->SetUserInitialization( new CASCADEPhysicsList() );

  // action initialization
  CASCADEActionInitialization* ai = new CASCADEActionInitialization;
  runManager->SetUserInitialization( ai );

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  runManager->Initialize();
  // runManager->BeamOn(1);

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // visualization
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // ui manager
  G4UImanager* uiManager = G4UImanager::GetUIpointer();
  if ( !uiExecutive )
  {
    G4String command = "/control/execute ";
    uiManager->ApplyCommand(command + macroFile);
  } else {
    uiManager->ApplyCommand("/control/execute vis.mac");
    uiExecutive->SessionStart();
    delete uiExecutive;
  }

  delete visManager;
  delete runManager;

  return 0;

}
