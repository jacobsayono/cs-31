#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H
#include <string>

class ZooAnimal {
    public:
        ZooAnimal(std::string n, int cn, int wd, int w);
        std::string getName();
    private:
        std::string name;
        int cageNumber;
        int weightDate;
        int weight;
};

#endif /* ZOOANIMAL_H */