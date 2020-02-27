#include "animal.hh"

#include <iostream>

int main(int argc, char* argv[]) {
  std::ostream& out = std::cout;
  Cat fluffy("fluffy"), simba("simba");
  Dog fido("fido"), rufus("rufus");
  Cow bossy("bossy"), bessie("bessie");
  // Animal animals[] = { fido, fluffy }; Abstract classes cannot be created as objects without using pointers
    const Animal *animals[] = { 
    &bessie,
    &bossy,
    &fido,
    &fluffy,
    &rufus,
    &simba,
  };
  for (auto animalP : animals) {
    //out << animalP->name << " says " << animalP->says() << std::endl;
    out << animalP->name << " eats " << animalP->eats() << std::endl;
  }
}
