#include "DetectorConstruction.hh"

#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Ellipsoid.hh"


G4VPhysicalVolume *DetectorConstruction::Construct()
{

	G4int nLayers = 60;
	G4NistManager* nist = G4NistManager::Instance();


	// World
	G4double env_size = 5.0*cm;

	G4Material* AIR = nist->FindOrBuildMaterial("G4_AIR");

	G4Box *universe_s = new G4Box("universe_S", 0.5 * env_size, 0.5 * env_size, 0.5* env_size);

	auto universe_log = new G4LogicalVolume(universe_s, AIR,"universe_L",0,0,0);                                       

	auto physWorld = new G4PVPlacement(0, G4ThreeVector(), universe_log,"universe_P", 0, false, 0, checkOverlaps);
 
 
  	//detector

	G4Material* PB = nist->FindOrBuildMaterial("G4_Pb");
	
  	auto det_s = new G4Box("det_S", 0.3*env_size, 0.3*env_size, 0.3/nLayers *env_size); 

  	det_log = new G4LogicalVolume(det_s, PB, "det_L");
  	
  	for(G4int i = 0; i < nLayers; i++)
	{
            	auto det_phys = new G4PVPlacement(0, G4ThreeVector(0, 0, -0.3*env_size+(i+0.5)*0.6*env_size/nLayers), det_log, "det_P", universe_log, false, i*nLayers, 1);
	}

  	
  	//
  	//fScoringVolume = body_log;
  	
  	return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
	SensitiveDetector *sensDet1 = new SensitiveDetector("SensitiveDetector1");
	det_log->SetSensitiveDetector(sensDet1);
	//SensitiveDetector *sensDet2 = new SensitiveDetector("SensitiveDetector2");
	//foil_log->SetSensitiveDetector(sensDet2);
}
