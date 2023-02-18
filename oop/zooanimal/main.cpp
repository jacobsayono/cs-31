#include <iostream>
#include "zooanimal.h"

int main() {
    ZooAnimal z("Panda", 1, 2, 3);
    std::cout << z.getName() << std::endl;
}