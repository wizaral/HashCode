#pragma once
#include "entity.hpp"

struct Sort {
    virtual void sort(Entities &entities) = 0;
};

struct Sort0 : Sort {
    void sort(Entities &entities) override;
};

struct Sort1 : Sort {
    int max = std::numeric_limits<int>::max();

    Sort1() = default;
    Sort1(int max);

    void sort(Entities &entities) override;
};

struct Sort2 : Sort1 {
    using Sort1::Sort1;

    void sort(Entities &entities) override;
};
