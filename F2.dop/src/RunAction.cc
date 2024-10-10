#include "RunAction.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyRunAction::MyRunAction()
{}


MyRunAction::~MyRunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	
	man->OpenFile("output.root");
	
	man->CreateNtuple("Hits", "Hits");
    	man->CreateNtupleDColumn("fZ");
    	man->CreateNtupleDColumn("E");
    	man->FinishNtuple(0);
    	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyRunAction::EndOfRunAction(const G4Run* run)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->Write();
	man->CloseFile();
}
//oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
