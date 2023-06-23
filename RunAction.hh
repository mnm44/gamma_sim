#ifndef RunAction_hh
#define RunAction_hh

#include "Analysis.hh"
#include "G4UserRunAction.hh"
#include "globals.hh"

class RunAction : public G4UserRunAction
{
public:
    RunAction();
    ~RunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif
