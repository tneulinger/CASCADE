#include "CASCADEPrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

CASCADEPrimaryGeneratorAction::CASCADEPrimaryGeneratorAction() :
  G4VUserPrimaryGeneratorAction()
{
  fParticleSource = new G4GeneralParticleSource;

  // set type of particle
  // G4ParticleDefinition* particleDef =
  //   G4ParticleTable::GetParticleTable()->FindParticle( "alpha" );
  // fParticleSource->SetParticleDefinition( particleDef );

  // set position
  // fParticleSource->SetParticlePosition(
  //     G4ThreeVector( 0.0, 0.0, -1.5*CLHEP::cm ) );

  // set momentum direction and energy
  // fParticleGun->SetParticleMomentumDirection( G4ThreeVector(0.0, 0.0, 1) );
  // fParticleGun->SetParticleEnergy( 5.48*CLHEP::MeV );
}

CASCADEPrimaryGeneratorAction::~CASCADEPrimaryGeneratorAction()
{
  delete fParticleSource;
}

void CASCADEPrimaryGeneratorAction::GeneratePrimaries(G4Event* evt)
{
	fParticleSource->GeneratePrimaryVertex(evt);
}
