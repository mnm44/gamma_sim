#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"

#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4double a, z;
  G4double density;
  G4int ncomponents, natoms;

  G4Element* C = new G4Element("Carbon"  ,"C" , z= 6., a= 12.01*g/mole);
  G4Element* F = new G4Element("Fluorine","N" , z= 9., a= 18.99*g/mole);
  G4Element* H  = new G4Element("Hydrogen" ,"H" , z= 1., a=   1.01*g/mole);
  G4double fractionmass;
 
  G4Material* Panel =
  new G4Material("Panel", density= 1.023*g/cm3, ncomponents=2);
  Panel->AddElement(H, fractionmass=8.*perCent);
  Panel->AddElement(C, fractionmass=92.*perCent);

  G4cout << Panel << G4endl;

  G4double  fBoxSize = 25*cm;
  G4double  fBoxThickness = 2.54*cm;

  G4Box* solidWorld = new G4Box("Container",fBoxSize/2,fBoxSize/2,fBoxThickness/2);
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld,Panel,"Panel");
  G4VPhysicalVolume* physiWorld = new G4PVPlacement(0,G4ThreeVector(),logicWorld,"Panel",0,false,0);

  return physiWorld;
}
