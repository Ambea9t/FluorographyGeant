
#ifndef F1DetectorConstruction_h
#define F1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "globals.hh"

#include "G4GlobalMagFieldMessenger.hh"

#include "G4SDManager.hh"
#include "G4SDChargedFilter.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSTrackLength.hh"

//#include "G4RunManager.hh"
//#include "G4SystemOfUnits.hh"
//#include "G4AnalysisManager.hh"
#include "Detector.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4GlobalMagFieldMessenger;

/// Detector construction class to define materials and geometry.


  
class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction() = default;
    ~DetectorConstruction() override = default;

    G4VPhysicalVolume* Construct() override;

  private:
    
    G4LogicalVolume *det_log;
    
    virtual void ConstructSDandField();

    G4bool checkOverlaps = true;
};



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
