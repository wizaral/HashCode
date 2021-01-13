#pragma once
#include "entity.hpp"

#include "crossover.hpp"
#include "generator.hpp"
#include "mutation.hpp"
#include "filter.hpp"
#include "search.hpp"
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
    std::unique_ptr<Filter> m_filter;
    std::unique_ptr<Search> m_search;
    std::unique_ptr<Sort> m_sort;

public:
    virtual ~Population() = default;
    Population() = default;

    Population(
        std::unique_ptr<Crossover> crossover,
        std::unique_ptr<Generator> generator,
        std::unique_ptr<Mutation> mutation,
        std::unique_ptr<Filter> filter,
        std::unique_ptr<Search> search,
        std::unique_ptr<Sort> sort);

    Slices &slices();
    Entities &entities();

    const Slices &slices() const;
    const Entities &entities() const;

    int age() const;
    int max() const;

    Population &set_crossover(std::unique_ptr<Crossover> crossover);
    Population &set_generator(std::unique_ptr<Generator> generator);
    Population &set_mutation(std::unique_ptr<Mutation> mutation);
    Population &set_filter(std::unique_ptr<Filter> filter);
    Population &set_search(std::unique_ptr<Search> search);
    Population &set_sort(std::unique_ptr<Sort> sort);

    void input(const char *file);
    void examine();

    virtual void algorithm(std::size_t iterations) = 0;
    virtual void print(Entities::iterator result) = 0;
};

class Population0 : public Population {
public:
    using Population::Population;

    void algorithm(std::size_t iterations) override;
    void print(std::vector<Entity>::iterator result) override;
};
