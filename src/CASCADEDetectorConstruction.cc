#include "CASCADEDetectorConstruction.hh"

#include "globals.hh"
#include "G4SystemOfUnits.hh"

// for materials
#include "G4NistManager.hh"

// for geometry
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"


// constructor
CASCADEDetectorConstruction::CASCADEDetectorConstruction()
{
  fScoringVolume = 0;
}

// detstructor
CASCADEDetectorConstruction::~CASCADEDetectorConstruction()
{
  //
}

// Construct() method
G4VPhysicalVolume* CASCADEDetectorConstruction::Construct()
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // 1. WORLD: box filled with low density hydrogen

  // ----- world solid -----
  G4double worldXSize = 35.0*CLHEP::cm;
  G4double worldYSize = 35.0*CLHEP::cm;
  G4double worldZSize = 10.0*CLHEP::cm;
  G4Box* worldSolid = new G4Box(
    "solid-World",  // name
    0.5*worldXSize, // half x-size
    0.5*worldYSize, // half y-size
    0.5*worldZSize  // half z-size
    );

  // ----- world logical -----
  G4double zet      = 1.0;
  G4double amass    = 1.01*CLHEP::g/CLHEP::mole;
  G4double density  = CLHEP::universe_mean_density;
  G4double pressure = 3.e-18*CLHEP::pascal;
  G4double tempture = 2.73*CLHEP::kelvin;
  G4Material* matWorld = new G4Material(
    "Galactic",  // name
    zet,         // atomic number
    amass,       // atomic mass
    density,     // density
    kStateGas,   // phase
    tempture,    // temperature
    pressure     // pressure
    );
  // G4cout << matWorld << G4endl;
  G4LogicalVolume* worldLogical = new G4LogicalVolume(
    worldSolid,     // world solid volume
    matWorld,       // world material
    "logical-World" // name
    );

  // ----- world physical -----
  G4VPhysicalVolume* worldPhysical = new G4PVPlacement(
    nullptr,                      // no rotation
    G4ThreeVector(0.0, 0.0, 0.0), // no translation
    worldLogical,                 // world logical volume
    "World",                      // name
    nullptr,                      // no mother volume
    false,                        // ?
    0                             // copy number
    );

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  // 2. TARGET: slab of balance gas

  // ----- target solid -----
  G4double targetXSize = 27.0*CLHEP::cm;
  G4double targetYSize = 27.0*CLHEP::cm;
  G4double targetZSize = 3.0*CLHEP::cm;
  G4Box* targetSolid = new G4Box(
    "solid-Target",  // name
    0.5*targetXSize, // half x-size
    0.5*targetYSize, // half y-size
    0.5*targetZSize  // half z-size
    );

  // ----- target logical -----
  // Note: there are some things I don't understand about the methods that the
  // G4Material object has. For example matAr->GetDensity() returns a value that
  // appears to be the mass density in g/cm3 divided by the elementary charge
  // 1.602e-19 C. The pressure (from GetPressure() ) seems to have something
  // similar going on. For this reason, I looked up the properties of the
  // materials from the NIST database and just copied the densities and molar
  // mass from there.
  //
  // Ar properties:
  G4NistManager* mat = G4NistManager::Instance();
  G4Material* matAr  = mat->FindOrBuildMaterial("G4_Ar");
  // G4cout << matAr << G4endl; // has info about material properties
  G4double densityAr      = 1.662*CLHEP::mg/CLHEP::cm3;
  G4double molarMassAr    = 39.948*CLHEP::g/CLHEP::mole;
  //
  // CO2 properties:
  G4Material* matCO2 = mat->FindOrBuildMaterial("G4_CARBON_DIOXIDE");
  // G4cout << matCO2 << G4endl; // has info about material properties
  G4double densityCO2     = 1.842*CLHEP::mg/CLHEP::cm3;
  G4double molarMassCO2   = 44.009*CLHEP::g/CLHEP::mole;
  //
  // Define the balance gas: mixture of 85% argon, 15% carbon carbon dioxide
  G4double molFractionAr  = 0.85;
  G4double molFractionCO2 = 0.15;
  G4double massFractionAr  = (molarMassAr*molFractionAr)/
    (molarMassAr*molFractionAr + molarMassCO2*molFractionCO2);
  G4double massFractionCO2 = (molarMassCO2*molFractionCO2)/
    (molarMassAr*molFractionAr + molarMassCO2*molFractionCO2);
  G4double densityBalanceGas =
    molFractionAr*densityAr + molFractionCO2*densityCO2;
  G4Material* matBalanceGas = new G4Material(
    "Balance Gas",     // name
    densityBalanceGas, // density
    2 // number of components
    );
  matBalanceGas->AddMaterial(matAr,  massFractionAr);
  matBalanceGas->AddMaterial(matCO2, massFractionCO2);
  // G4cout << *(G4Material::GetMaterialTable()) << G4endl;
  //
  G4LogicalVolume* targetLogical
    = new G4LogicalVolume(
      targetSolid,   // target solid
      matBalanceGas, // target material
      "logic-Target" // name
      );
  // set scoring volume to target logical volume 
  fScoringVolume = targetLogical;

  // ----- target physical -----
  G4VPhysicalVolume* targetPhysical
    = new G4PVPlacement(
      nullptr,
      G4ThreeVector(0.0, 0.0, 0.0),
      targetLogical,
      "Target",
      worldLogical,
      false,
      0
      );

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  return worldPhysical;

}
