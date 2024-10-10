
#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"


PrimaryGenerator::PrimaryGenerator():G4VUserPrimaryGeneratorAction(), fParticleGun(0)
{
	fParticleGun = new G4GeneralParticleSource();
}


PrimaryGenerator::~PrimaryGenerator()
{
	delete fParticleGun;
}


void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
	fParticleGun->GeneratePrimaryVertex(anEvent);
}

