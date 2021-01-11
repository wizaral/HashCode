#include "sort.hpp"

void Sort0::sort(Entities &entities) {
    std::sort(entities.begin(), entities.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.score() > rhs.score();
    });
}
