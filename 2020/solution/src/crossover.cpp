#include "crossover.hpp"

Entities Crossover0::crossover(const Entities &entities) {
    Entities copy = entities;

    for (std::size_t i = 0, j = copy.size() / 2; i < j; i += 2) {
        if (copy[i].indexes().size() < copy[i + 1].indexes().size()) {
            crossover(copy[i].indexes(), copy[i + 1].indexes());
        } else {
            crossover(copy[i + 1].indexes(), copy[i].indexes());
        }
    }
    return copy;
}

void Crossover0::crossover(Indexes &lhs, Indexes &rhs) {
    std::swap_ranges(lhs.begin(), lhs.begin() + lhs.size() / 2, rhs.begin());
}
