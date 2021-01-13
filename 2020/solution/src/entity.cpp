#include "entity.hpp"

Entity::Entity(Indexes &&indexes)
: m_indexes(std::move(indexes)) {}

Indexes &Entity::indexes() {
    return m_indexes;
}

const Indexes &Entity::indexes() const {
    return m_indexes;
}

int Entity::score() const {
    return m_score;
}

void Entity::examine(const Slices &slices) {
    m_score = 0;

    for (std::size_t i = 0, j = slices.size(); i < j; ++i) {
        m_score += slices[i] * m_indexes[i];
    }
}
