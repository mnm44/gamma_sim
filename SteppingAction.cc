#include "SteppingAction.hh"
#include "G4AnalysisManager.hh"

SteppingAction::SteppingAction(EventAction *eventAction)
{
    fEventAction = eventAction;
}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step *step)
{
    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);
    G4double posX = step->GetPostStepPoint()->GetPosition().x();
    G4double posY = step->GetPostStepPoint()->GetPosition().y();
    G4double posZ = step->GetPostStepPoint()->GetPosition().z();
    
    G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
    analysisMan->FillNtupleDColumn(0, 2, posX);
    analysisMan->FillNtupleDColumn(0, 3, posY);
    analysisMan->FillNtupleDColumn(0, 4, posZ);
    
    analysisMan->AddNtupleRow(0);

}
