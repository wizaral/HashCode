#pragma once
#include "entity.hpp"

struct Generator {
    virtual Entities generate(std::size_t slices) = 0;
};

struct Generator0 : Generator {
    Entities generate(std::size_t slices) override;
};
