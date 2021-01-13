#include "generator.hpp"

Entities Generator0::generate(std::size_t slices) {
    std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> uid(0, slices - 1);
    Entities entities;

    for (std::size_t i = 0; i < 40'000; ++i) {
        Indexes indexes(slices);

        for (std::size_t i = 0, j = uid(mt); i < j; ++i) {
            indexes[i] = !indexes[i];
        }
        std::shuffle(indexes.begin(), indexes.end(), mt);
        entities.emplace_back(std::move(indexes));
    }
    return entities;
}

// ================================================================================================================== //
