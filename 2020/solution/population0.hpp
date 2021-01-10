#pragma once
#include "population.hpp"

class Population0 : public Population {
public:
    void generate() override;
    void algorithm() override;
    void print(std::vector<Entity>::iterator result) override;

    void sort() override;
    void filter() override;
    void examine() override;
    void mutation() override;
    void crossover() override;
};
