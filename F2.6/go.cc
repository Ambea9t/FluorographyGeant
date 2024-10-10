
#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "PhysicsList.hh"

#include "G4RunManagerFactory.hh"
#include "G4SteppingVerbose.hh"
#include "G4UImanager.hh"
#include "G4ScoringManager.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"


int main(int argc,char** argv)
{
 
  G4UIExecutive* ui = nullptr;
  ui = new G4UIExecutive(argc, argv); 

  auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
    
  G4ScoringManager * scManager = G4ScoringManager::GetScoringManager();
  scManager->SetVerboseLevel(1);
  

  runManager->SetUserInitialization(new DetectorConstruction());


  runManager->SetUserInitialization(new PhysicsList());
  

  runManager->SetUserInitialization(new ActionInitialization());


  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();


  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  

  UImanager->ApplyCommand("/control/execute vis.mac");
  ui->SessionStart();

  delete visManager;
  delete runManager;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
