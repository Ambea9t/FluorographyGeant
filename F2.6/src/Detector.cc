
#include "Detector.hh"


SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name){}


SensitiveDetector::~SensitiveDetector(){}


G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();
	G4ParticleDefinition * fpParticleDefinition = track->GetDefinition();
	G4String namePart = fpParticleDefinition->GetParticleName();
	if(namePart=="gamma")
	{
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
	
	G4double ePart = preStepPoint->GetKineticEnergy();
	G4ThreeVector posPart = preStepPoint->GetPosition();
	//G4cout << "Position: " << posPart << G4endl;
	
	//const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	//G4int copyNo = touchable->GetCopyNumber();
	//G4cout << "Copy number: " << copyNo << G4endl;
	//G4VPhysicalVolume *physVol = touchable->GetVolume();
    	//G4ThreeVector posDetector = physVol->GetTranslation();
    	//G4cout << "Detector position: " << posDetector << G4endl;
    	
    	//G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	G4AnalysisManager *man = G4AnalysisManager::Instance();
    	//man->FillNtupleIColumn(0, evt);
        man->FillNtupleDColumn(0, posPart[0]);
        man->FillNtupleDColumn(1, posPart[1]);
        man->FillNtupleDColumn(2, ePart);
        man->AddNtupleRow(0);
        }
	return true;
}

