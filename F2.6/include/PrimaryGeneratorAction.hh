
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

class G4GeneralParticleSource;
//class G4Event;
//class G4ParticleGun;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGenerator();
   ~PrimaryGenerator();
   
    virtual void GeneratePrimaries(G4Event*);

    
  private:
    G4GeneralParticleSource* fParticleGun;
};

