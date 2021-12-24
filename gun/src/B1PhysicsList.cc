/// \file B1DetectorConstruction.hh
/// \brief Definition of the B1DetectorConstruction class

#include "B1PhysicsList.hh"

B1PhysicsList::B1PhysicsList():G4VModularPhysicsList(){
  // Default physics
  RegisterPhysics(new G4DecayPhysics());

  // EM physics
  RegisterPhysics(new G4EmStandardPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());
}

B1PhysicsList::~B1PhysicsList(){
}

void B1PhysicsList::SetCuts(){
  G4VUserPhysicsList::SetCuts();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


