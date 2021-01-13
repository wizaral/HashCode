#pragma once
#include "entity.hpp"

struct Filter {
    virtual void filter(Entities &entities) = 0;
};

struct Filter0 : Filter {
    void filter(Entities &entities) override;
};

struct Filter1 : Filter {
    int max = std::numeric_limits<int>::max();

    void filter(Entities &entities) override;
};
