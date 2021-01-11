#pragma once
#include "entity.hpp"

struct Sort {
    virtual void sort(Entities &entities) = 0;
};

struct Sort0 : Sort {
    void sort(Entities &entities) override;
};
