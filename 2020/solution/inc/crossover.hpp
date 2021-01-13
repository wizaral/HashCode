#pragma once
#include "entity.hpp"

struct Crossover {
    virtual Entities crossover(const Entities &entities) = 0;
};

struct Crossover0 : Crossover {
    Entities crossover(const Entities &entities) override;
};
