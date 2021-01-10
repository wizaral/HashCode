#pragma once
#include "entity.hpp"

/**
 * Generic Algorithm
 */

using Entities = std::vector<Entity>;

class Population {
protected:
    Slices m_slices;
    Entities m_entities;

    int m_age = 0;
    int m_max = 0;

public:
    virtual ~Population() = default;
    Population() = default;
    Population(Slices &&slices);

    Slices &slices();
    Entities &entities();

    const Slices &slices() const;
    const Entities &entities() const;

    int age() const;
    int max() const;

    void input(const char *file);

    virtual void generate() = 0;
    virtual void algorithm() = 0;
    virtual void print(Entities::iterator result) = 0;

    virtual void sort() = 0;
    virtual void filter() = 0;
    virtual void examine() = 0;
    virtual void mutation() = 0;
    virtual void crossover() = 0;
};
