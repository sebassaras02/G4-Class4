/// \file B1DetectorConstruction.hh
/// \brief Definition of the B1DetectorConstruction class

#ifndef B1Physics_h
#define B1Physics_h

#include "globals.hh"
#include "G4VModularPhysicsList.hh"
#include "G4VUserPhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

class B1PhysicsList: public G4VModularPhysicsList{
  public:
      B1PhysicsList();
      ~B1PhysicsList();
  void SetCuts();
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

