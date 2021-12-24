//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1PrimaryGeneratorAction.cc
/// \brief Implementation of the B1PrimaryGeneratorAction class

#include "B1PrimaryGeneratorAction.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1PrimaryGeneratorAction::B1PrimaryGeneratorAction()
{
    fparticlegun= new G4ParticleGun(1);
    // the 1 is the number of particles per event
}

B1PrimaryGeneratorAction::~B1PrimaryGeneratorAction()
{
    delete fparticlegun;
}

void B1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    // call a particle table
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    // call a variable the particle that we want
    G4String particleName = "gamma";
    // find this variable in the particle table
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName);

    // add properties of simulation to the generator

    fparticlegun->SetParticleDefinition(particle);
    fparticlegun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    fparticlegun->SetParticleEnergy(2.*MeV);
    // generate an event with the particle
    fparticlegun->GeneratePrimaryVertex(anEvent);
 }
