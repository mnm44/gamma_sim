#ifndef EventAction_hh
#define EventAction_hh

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"

#include "RunAction.hh"

class EventAction : public G4UserEventAction
{
public:
    EventAction(RunAction*);
    ~EventAction();
    
public:
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
    void AddEdep(G4double Edep)     {fTotalEnergyDeposit += Edep;};
    G4double GetEnergyDeposit()     {return fTotalEnergyDeposit;};
    
private:
    G4double fTotalEnergyDeposit;
};

#endif
