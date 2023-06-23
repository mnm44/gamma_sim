#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleDefinition.hh"
#include "G4PhysicalConstants.hh"
#include "Randomize.hh"

#include <G4GeneralParticleSource.hh>

PrimaryGenerator::PrimaryGenerator()
{
    fParticleGun = new G4GeneralParticleSource();
    
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "gamma";
    G4ParticleDefinition *particle = particleTable->FindParticle(particleName);
    
    
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->GetCurrentSource()->GetPosDist()->SetCentreCoords(G4ThreeVector(0.,0.,1.3*cm));
    fParticleGun->GetCurrentSource()->GetAngDist()->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
    fParticleGun->GetCurrentSource()->GetEneDist()->SetMonoEnergy(2614*keV);
    
}

PrimaryGenerator::~PrimaryGenerator()
{
    delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{

    fParticleGun->GeneratePrimaryVertex(anEvent);
}
