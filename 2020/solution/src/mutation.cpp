#include "mutation.hpp"

Entities Mutation0::mutation(const Entities &entities) {
    Entities copy = entities;

    for (std::size_t i = 0, j = copy.size(); i < j; ++i) {
        copy[i].mutation();
    }
    return copy;
}
