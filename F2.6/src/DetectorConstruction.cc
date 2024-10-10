
#include "DetectorConstruction.hh"

#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Ellipsoid.hh"


//DetectorConstruction::DetectorConstruction()

//DetectorConstruction::~DetectorConstruction(){}


G4VPhysicalVolume *DetectorConstruction::Construct()
{

	G4NistManager* nist = G4NistManager::Instance();


	// World
	nCols = 10;
    	nRows = 10;
	G4double env_size = 0.48*m;

	
	G4Material* AIR = nist->FindOrBuildMaterial("G4_AIR");

	G4Box *universe_s = new G4Box("universe_S", 0.5 * env_size, 0.5 * env_size, 1.9 * env_size);

	auto universe_log = new G4LogicalVolume(universe_s, AIR,"universe_L",0,0,0);                                       

	auto physWorld = new G4PVPlacement(0, G4ThreeVector(), universe_log,"universe_P", 0, false, 0, checkOverlaps);
 
 
	//body model
	
	G4Material* muscle = nist->FindOrBuildMaterial("G4_MUSCLE_SKELETAL_ICRP");
  
	auto body_s = new G4Box("body_S", 0.5 * env_size, 0.5 * env_size, 0.23 * env_size); 

	auto body_log = new G4LogicalVolume(body_s, muscle, "body_L",0,0,0);        

	auto body_phys = new G4PVPlacement(0, G4ThreeVector(0,0,1.6* env_size), body_log, "body_P", universe_log, false, 0, checkOverlaps);
  
  
  	//Lung
  	
	G4Material* LUNG = nist->FindOrBuildMaterial("G4_LUNG_ICRP");
  
  	G4Material* LUNG_and_AIR = new G4Material("LUNG_and_AIR", 0.201*g/cm3, 2);
   	LUNG_and_AIR->AddMaterial(LUNG, 98.2*perCent);
	LUNG_and_AIR->AddMaterial(AIR, 1.8*perCent);
  
  	auto lung_s = new G4Ellipsoid("lung_S", 0.2 * env_size, 0.3 * env_size, 0.15 * env_size, 0.0 * env_size, 0.0* env_size);

  	auto lung_log = new G4LogicalVolume(lung_s, LUNG_and_AIR, "lung_L"); 

  	new G4PVPlacement(0, G4ThreeVector( 0.22 * env_size, 0, 0* env_size), lung_log, "lung1", body_log, false, 1, checkOverlaps);
  
  	new G4PVPlacement(0, G4ThreeVector( -0.22 * env_size, 0, 0* env_size), lung_log, "lung2", body_log, false, 2, checkOverlaps);
  
  
  	//al foil
  	
  	G4Material* Al = nist->FindOrBuildMaterial("G4_Al");
  	
  	auto foil_s = new G4Box("foil_S", 0.1 * env_size, 0.1 * env_size, 0.5* mm); 

  	foil_log = new G4LogicalVolume(foil_s, Al, "foil_L");

  	auto foil_phys = new G4PVPlacement(0, G4ThreeVector( 0, 0, -1.7* env_size), foil_log, "foil_P", universe_log, false, 0, checkOverlaps);
  	
  	
  	//detector

  	auto det_s = new G4Box("det_S", 0.5*env_size/nRows, 0.5*env_size/nCols, 0.0001 * cm); 

  	det_log = new G4LogicalVolume(det_s, AIR, "det_L");
  	
  	for(G4int i = 0; i < nRows; i++)
	{
        	for(G4int j = 0; j < nCols; j++)
		{
            		auto det_phys = new G4PVPlacement(0, G4ThreeVector(-0.5*env_size+(i+0.5)*env_size/nRows, -0.5*env_size+(j+0.5)*env_size/nCols, 1.87* env_size), det_log, "det_P", universe_log, false, j+i*nCols, 1);
		}
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

