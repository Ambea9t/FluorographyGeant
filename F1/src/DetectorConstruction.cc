#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Ellipsoid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace F1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Envelope parameters
  //
  G4double env_size = 0.48*m;
  G4Material* muscle = nist->FindOrBuildMaterial("G4_MUSCLE_SKELETAL_ICRP");

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_size = 1.1*env_size;
  G4Material* AIR = nist->FindOrBuildMaterial("G4_AIR");
  G4Material* Al = nist->FindOrBuildMaterial("G4_Al");

  auto solidWorld = new G4Box("World",                           // its name
    0.5 * world_size, 0.5 * world_size, 0.7 * world_size);  // its size

  auto logicWorld = new G4LogicalVolume(solidWorld,  // its solid
    AIR,                                       // its material
    "World");                                        // its name

  auto physWorld = new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),                           // at (0,0,0)
    logicWorld,                                // its logical volume
    "World",                                   // its name
    nullptr,                                   // its mother  volume
    false,                                     // no boolean operation
    0,                                         // copy number
    checkOverlaps);                            // overlaps checking

  //
  // Envelope
  //
  auto solidEnv = new G4Box("Envelope",                    // its name
    0.5 * env_size, 0.5 * env_size, 0.2 * env_size);  // its size

  auto logicEnv = new G4LogicalVolume(solidEnv,  // its solid
    muscle,                                     // its material
    "Envelope");                                 // its name

  new G4PVPlacement(nullptr,  // no rotation
    G4ThreeVector(),          // at (0,0,0)
    logicEnv,                 // its logical volume
    "Envelope",               // its name
    logicWorld,               // its mother  volume
    false,                    // no boolean operation
    0,                        // copy number
    checkOverlaps);           // overlaps checking

  //
  //
  //
  G4Material* LUNG = nist->FindOrBuildMaterial("G4_LUNG_ICRP");
  
  G4Material* LUNG_and_AIR = new G4Material("LUNG_and_AIR", 0.201*g/cm3, 2);
   LUNG_and_AIR->AddMaterial(LUNG, 98.2*perCent);
   LUNG_and_AIR->AddMaterial(AIR, 1.8*perCent);
   
  G4ThreeVector pos1 = G4ThreeVector( 0.21 * env_size, 0, 0);
  G4ThreeVector pos2 = G4ThreeVector( -0.21 * env_size, 0, 0);
  G4ThreeVector pos3 = G4ThreeVector( 0, 0, -0.3* env_size);

  // Lung
  auto solidShape = new G4Ellipsoid("Shape",  // its name
  0.2 * env_size, 
  0.3 * env_size, 
  0.15 * env_size,
  0.0 * env_size,
   0.0* env_size);

  auto logicShape = new G4LogicalVolume(solidShape,  // its solid
    LUNG_and_AIR,                                        // its material
    "Shape");                                         // its name

  new G4PVPlacement(nullptr,  // no rotation
    pos2,                     // at position
    logicShape,              // its logical volume
    "Shape1",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    1,                        // copy number
    checkOverlaps);           // overlaps checking

  new G4PVPlacement(nullptr,  // no rotation
    pos1,                     // at position
    logicShape,              // its logical volume
    "Shape2",                 // its name
    logicEnv,                 // its mother  volume
    false,                    // no boolean operation
    2,                        // copy number
    checkOverlaps);           // overlaps checking
  // Set Shape as scoring volume
  
  auto Solid_Al = new G4Box("Al_Shape",                           // its name
    0.5 * world_size, 0.5 * world_size, 0.5* mm);  // its size

  auto logic_Al = new G4LogicalVolume(Solid_Al,  // its solid
    Al,                                       // its material
    "Al_Shape");                                        // its name

  new G4PVPlacement(nullptr,  // no rotation
    pos3,                           // at (0,0,0)
    logic_Al,                                // its logical volume
    "Al_Shape",                                   // its name
    logicWorld,                                   // its mother  volume
    false,                                     // no boolean operation
    0,                                         // copy number
    checkOverlaps);                            // overlaps checking
    
  //
  fScoringVolume = logicShape;
  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
