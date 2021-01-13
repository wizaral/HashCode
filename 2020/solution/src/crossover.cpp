#include "crossover.hpp"

Entities Crossover0::crossover(const Entities &entities) {
    Entities copy = entities;
    auto size = copy.front().indexes().size() / 2;

    for (std::size_t i = 0, j = copy.size() / 2; i < j; i += 2) {
        std::swap_ranges(copy[i].indexes().begin(), copy[i].indexes().begin() + size, copy[i + 1].indexes().begin());
    }
    return copy;
}

// ================================================================================================================== //
