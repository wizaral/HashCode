#pragma once
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

/**
 * Generic Algorithm
 */

using Slices = std::vector<int>;
using Indexes = std::vector<int>;

class Entity {
    Indexes m_indexes;
    int m_score = 0;

public:
    Entity() = default;
    Entity(Indexes &&indexes);

    Indexes &indexes();
    const Indexes &indexes() const;
    int score() const;

    void examine(const Slices &slices);
    void validate();

    void crossover(Entity &entity);
    void mutation();
};
