/*
** EPITECH PROJECT, 2019
** Droid.hpp
** File description:
** Droid.hpp
*/

#ifndef _DROID_HPP
#define _DROID_HPP

#include <iostream>
#include <string>

class Droid {
protected:
  private:
  std::string Id;
  size_t Energy;
  size_t const Attack;
  size_t const Toughness;
  std::string *Status;

public:
  Droid();
  ~Droid();
  Droid(Droid const &);
  Droid(std::string);

void setId(std::string);
void setEnergy(size_t);
void setStatus(std::string *);

  std::string getId() const;
  size_t      getEnergy() const;
  std::string *getStatus() const;
  size_t      getAttack() const;
  size_t      getToughness() const;

  Droid& operator=(Droid const &);
  bool operator==(Droid const &) const;
  bool operator!=(Droid const &) const;
  Droid& operator<<(size_t &value);
};

std::ostream& operator <<(std::ostream&, Droid const &) ;

#endif
