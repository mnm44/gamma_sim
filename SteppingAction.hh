#ifndef SteppingAction_hh
#define SteppingAction_hh

#include "G4USerSteppingAction.hh"
#include "G4Step.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"

class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction();
    
    virtual void UserSteppingAction(const G4Step*);
    
private:
    EventAction *fEventAction;
};

#endif
