#include "generator.hpp"

Entities Generator0::generate(std::size_t slices) {
    std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> uid(0, slices);
    Entities entities;

    for (std::size_t i = 0; i < 40'000; ++i) {
        Indexes indexes(slices);
        std::iota(indexes.begin(), indexes.end(), 0);

        std::size_t to_delete = uid(mt);
        for (std::size_t i = 0; i < to_delete; ++i) {
            indexes.erase(indexes.begin() + (mt() % indexes.size()));
        }

        entities.emplace_back(std::move(indexes));
    }
    return entities;
}
