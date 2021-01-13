#pragma once
#include "entity.hpp"

struct Mutation {
    virtual Entities mutation(const Entities &entities) = 0;
};

struct Mutation0 : Mutation {
    std::mt19937 mt;
    std::uniform_int_distribution<> uid;

    Mutation0(std::size_t b);
    Entities mutation(const Entities &entities) override;
};

struct Mutation1 : Mutation0 {
    using Mutation0::Mutation0;
    Entities mutation(const Entities &entities) override;
};
