
#include "RunAction.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"


RunAction::RunAction()
{
	auto analysisManager = G4AnalysisManager::Instance();
	analysisManager->SetVerboseLevel(1);
	analysisManager->SetNtupleMerging(true);
	
	analysisManager->CreateH1("X","X disribution", 10000, 0., 10000.);
	analysisManager->CreateH1("Y","Y disribution", 10000, 0., 10000.);
	analysisManager->CreateH1("E","E registration in detector", 100, 0., 100*MeV);
	
	analysisManager->CreateNtuple("Test", "Hits");
    	analysisManager->CreateNtupleDColumn("X");
    	analysisManager->CreateNtupleDColumn("Y");
    	analysisManager->CreateNtupleDColumn("E");
    	analysisManager->FinishNtuple();
}


RunAction::~RunAction(){}


void RunAction::BeginOfRunAction(const G4Run* )
{
	auto analysisManager = G4AnalysisManager::Instance();
	
	analysisManager->OpenFile("output.root"); 
}


void RunAction::EndOfRunAction(const G4Run* )
{
	auto analysisManager = G4AnalysisManager::Instance();

	analysisManager->Write();
	analysisManager->CloseFile();
}

