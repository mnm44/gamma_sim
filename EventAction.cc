#include "EventAction.hh"
#include "Analysis.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"


EventAction::EventAction(RunAction*)
{
    fTotalEnergyDeposit = 0.;
}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{
    fTotalEnergyDeposit = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
    G4cout << "Energy deposition: " << fTotalEnergyDeposit << G4endl;
    
    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    
    G4AnalysisManager* analysisMan = G4AnalysisManager::Instance();
    analysisMan->FillNtupleIColumn(0, 0, evt);
    analysisMan->FillNtupleDColumn(0, 1, fTotalEnergyDeposit/MeV);

    analysisMan->AddNtupleRow(0);
}
