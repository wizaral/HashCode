#include "sort.hpp"

void Sort0::sort(Entities &entities) {
    std::sort(entities.begin(), entities.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.score() > rhs.score();
    });
}

// ================================================================================================================== //

Sort1::Sort1(int max)
: max(max) {}

void Sort1::sort(Entities &entities) {
    std::partition(entities.begin(), entities.end(), [this](const auto &e) {
        return e.score() <= max;
    });
}

// ================================================================================================================== //

void Sort2::sort(Entities &entities) {
    std::sort(entities.begin(), entities.end(), [this](const auto &lhs, const auto &rhs) {
        return lhs.score() > rhs.score();
    });

    std::stable_partition(entities.begin(), entities.end(), [this](const auto &e) {
        return e.score() <= max;
    });
}

// ================================================================================================================== //
