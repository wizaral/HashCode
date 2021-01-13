#pragma once
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <vector>

using Slices = std::vector<int>;
using Indexes = std::vector<bool>;

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
};

using Entities = std::vector<Entity>;
