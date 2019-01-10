/*
** EPITECH PROJECT, 2019
** Droid.cpp
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

std::ostream& operator <<(std::ostream& os, Droid const& droid)
{
  os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
  return os;
}

Droid::Droid() : Id(""), Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
  std::cout << "Droid '' Activated" << std::endl;
}

Droid::Droid(std::string Id) : Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
  this->Id = Id;
  std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : Id(droid.getId()), Energy(droid.getEnergy()), Attack(25), Toughness(15), Status(new std::string(*droid.getStatus()))
{
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

 Droid&  Droid::operator=(Droid const &droid) {
  if (&droid != this)
    {
      this->Id = droid.getId();
      this->Energy = droid.getEnergy();
      if (this->Status)
        delete this->Status;
      this->Status = new std::string(*droid.getStatus());
    }
  return *this;
}


Droid::~Droid() {
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
    delete Status;
}

size_t  Droid::getEnergy() const{
  return Energy;
}

void    Droid::setEnergy(size_t Energy) {
  if (Energy > 100)
    this->Energy = 100;
  else
    this->Energy = Energy;
}

std::string Droid::getId() const {
  return Id;
}
void    Droid::setId(std::string Id) {
  this->Id = Id;
}

std::string *Droid::getStatus() const {
  return Status;
}

void Droid::setStatus(std::string *status) {
  this->Status = status;
}

size_t Droid::getAttack() const{
  return Attack;
}

size_t Droid::getToughness() const {
  return Toughness;
}


//operators

bool Droid::operator==(Droid const &droid) const {
  return (this->Id == droid.getId() && this->Status->compare(*droid.getStatus()) == 0 && this->Energy == droid.getEnergy());
}


bool Droid::operator!=(Droid const &droid) const {
  return (this->Id != droid.getId() || this->Status->compare(*droid.getStatus()) != 0 || this->Energy != droid.getEnergy());
}

Droid &Droid::operator<<(size_t &value) {
    size_t temp = 100 - Energy;

    if (value > temp) {
        Energy = 100;
        value -= temp;
    } else {
        Energy += value;
        Energy = 0;
    }
    return *this;
}
