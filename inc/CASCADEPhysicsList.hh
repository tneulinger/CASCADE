#ifndef CASCADEPhysicsList_hh
#define CASCADEPhysicsList_hh

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class CASCADEPhysicsList : public G4VModularPhysicsList
{
  public:
    CASCADEPhysicsList();
    virtual ~ CASCADEPhysicsList();

    virtual void ConstructParticle();
    virtual void ConstructProcess();

  private:
    G4VPhysicsConstructor* fEmPhysicsList;
    G4VPhysicsConstructor* fDecay;
};

#endif
