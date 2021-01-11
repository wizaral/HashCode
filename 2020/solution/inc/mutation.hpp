#pragma once
#include "entity.hpp"

struct Mutation {
    virtual Entities mutation(const Entities &entities) = 0;
};

struct Mutation0 : Mutation {
    Entities mutation(const Entities &entities) override;
};
