
#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

class G4GeneralParticleSource;
//class G4Event;
//class G4ParticleGun;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
  public:
    MyPrimaryGenerator();
   ~MyPrimaryGenerator();

    // method to access particle gun
    //const G4GeneralParticleSource* GetGeneralParticleSource() const { return fGeneralParticleSource; }
    
    virtual void GeneratePrimaries(G4Event*);

    
  private:
    G4GeneralParticleSource* fParticleGun;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


