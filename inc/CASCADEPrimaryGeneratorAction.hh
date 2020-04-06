#ifndef CASCADEPrimaryGeneratorAction_hh
#define CASCADEPrimaryGeneratorAction_hh

#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"

// forward declarations
class G4ParticleGun;
class G4Event;

class CASCADEPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{

  public:

    CASCADEPrimaryGeneratorAction();

    virtual ~CASCADEPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event*);

  private:

    // G4ParticleGun* fParticleGun;
    G4GeneralParticleSource* fParticleSource;

};


#endif
