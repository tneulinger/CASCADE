#include "globals.hh"
#include "G4RunManager.hh"
#include "G4PhysListFactory.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "CASCADEDetectorConstruction.hh"
#include "CASCADEActionInitialization.hh"

int main(int argc, char** argv)
{

  // interactive or batch mode
  G4String macroFile = "";
  G4UIExecutive* uiExecutive = nullptr;
  if (argc==1)
  {
    uiExecutive = new G4UIExecutive(argc, argv);
  } else {
    macroFile = argv[1];
    G4cout << macroFile << G4endl;
  }

  // run manager
  G4RunManager* runManager = new G4RunManager;

  // detector construction
  CASCADEDetectorConstruction* detector = new CASCADEDetectorConstruction;
  runManager->SetUserInitialization( detector );

  // physics list
  G4String physListName = "FTFP_BERT_EMZ";
  G4PhysListFactory physListFactory;
  G4VModularPhysicsList* physList
   = physListFactory.GetReferencePhysList( physListName );
  runManager->SetUserInitialization( physList );

  // action initialization
  CASCADEActionInitialization* ai = new CASCADEActionInitialization;
  runManager->SetUserInitialization( ai );

  runManager->Initialize();
  // runManager->BeamOn(1);

  // visualization
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  // ui manager
  G4UImanager* uiManager = G4UImanager::GetUIpointer();
  if ( !uiExecutive )
  {
    G4String command = "/control/execute ";
    uiManager->ApplyCommand(command + macroFile);
  } else {
    uiExecutive->SessionStart();
    delete uiExecutive;
  }

  delete visManager;

  delete runManager;

  return 0;

}
