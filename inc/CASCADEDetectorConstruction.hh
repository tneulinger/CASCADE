#ifndef CASCADEDetectorConstruction_hh
#define CASCADEDetectorConstruction_hh

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"

class CASCADEDetectorConstruction : public G4VUserDetectorConstruction
{

  public:

    // constructor
    CASCADEDetectorConstruction();

    // detstructor
    virtual ~CASCADEDetectorConstruction();

    // Construct() method
    virtual G4VPhysicalVolume* Construct();

    // get pointer to scoring volume
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  private:

    G4LogicalVolume* fScoringVolume;

};

#endif
