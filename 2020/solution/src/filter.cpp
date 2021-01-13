#include "filter.hpp"

void Filter0::filter(Entities &entities) {
    entities.resize(entities.size() / 4);
}

// ================================================================================================================== //

void Filter1::filter(Entities &entities) {
    entities.erase(std::remove_if(entities.begin(), entities.end(), [this](const auto &e) {
        return e.score() > max;
    }), entities.end());

    entities.resize(entities.size() / 4);
}
