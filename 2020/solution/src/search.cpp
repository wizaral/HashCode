#include "search.hpp"

Search0::Search0(int max)
: max(max) {}

Entities::iterator Search0::search(Entities &entities) {
    return std::lower_bound(entities.begin(), entities.end(), max, [](const auto &e, int val) {
        return e.score() > val;
    });
}

// ================================================================================================================== //

Entities::iterator Search1::search(Entities &entities) {
    return entities.begin();
}

// ================================================================================================================== //
