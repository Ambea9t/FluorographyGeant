
#ifndef F1ActionInitialization_h
#define F1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

namespace F1
{

class ActionInitialization : public G4VUserActionInitialization
{
  public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
