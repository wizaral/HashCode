#pragma once
#include "entity.hpp"

struct Search {
    virtual Entities::iterator search(Entities &entities) = 0;
};

struct Search0 : Search {
    int max = std::numeric_limits<int>::max();

    Search0() = default;
    Search0(int max);

    Entities::iterator search(Entities &entities) override;
};

struct Search1 : Search {
    Entities::iterator search(Entities &entities) override;
};
