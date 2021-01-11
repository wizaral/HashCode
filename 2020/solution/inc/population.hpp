#pragma once
#include "entity.hpp"
#include "crossover.hpp"
#include "generator.hpp"
#include "mutation.hpp"
#include "sort.hpp"

class Population {
protected:
    std::string m_file;

    Slices m_slices;
    Entities m_entities;

    int m_age = 0;
    int m_max = 0;

    std::unique_ptr<Crossover> m_crossover;
    std::unique_ptr<Generator> m_generator;
    std::unique_ptr<Mutation> m_mutation;
    std::unique_ptr<Sort> m_sort;

public:
    virtual ~Population() = default;

    Population(
        std::unique_ptr<Crossover> crossover,
        std::unique_ptr<Generator> generator,
        std::unique_ptr<Mutation> mutation,
        std::unique_ptr<Sort> sort);

    Slices &slices();
    Entities &entities();

    const Slices &slices() const;
    const Entities &entities() const;

    int age() const;
    int max() const;

    void input(const char *file);
    void examine();

    virtual void algorithm() = 0;
    virtual void print(Entities::iterator result) = 0;
    virtual void filter() = 0;
};

class Population0 : public Population {
public:
    using Population::Population;

    void algorithm() override;
    void print(std::vector<Entity>::iterator result) override;
    void filter() override;
};
