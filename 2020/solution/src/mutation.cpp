#include "mutation.hpp"

Mutation0::Mutation0(std::size_t b)
: mt(std::chrono::steady_clock::now().time_since_epoch().count())
, uid(0, b - 1) {}

Entities Mutation0::mutation(const Entities &entities) {
    Entities copy = entities;

    for (auto &i : copy) {
        auto pos = uid(mt);
        i.indexes()[pos] = !i.indexes()[pos];
    }
    return copy;
}

// ================================================================================================================== //

Entities Mutation1::mutation(const Entities &entities) {
    Entities copy = entities;

    for (auto &i : copy) {
        for (int j = 0, k = 10; j < k; ++j) {
            int pos = uid(mt);
            i.indexes()[pos] = !i.indexes()[pos];
        }
    }
    return copy;
}
