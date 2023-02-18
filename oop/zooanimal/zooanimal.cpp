#include "zooanimal.h"
#include <string>

ZooAnimal::ZooAnimal(std::string n, int cn, int wd, int w) {
    name = n;
    cageNumber = cn;
    weightDate = wd;
    weight = w;
}

std::string ZooAnimal::getName() {
    return name;
}