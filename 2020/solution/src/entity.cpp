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

void Entity::examine(const Indexes &slices) {
    m_score = 0;

    for (auto i : m_indexes) {
        m_score += slices[i];
    }
}

void Entity::validate() {
    std::sort(m_indexes.begin(), m_indexes.end());
    m_indexes.erase(std::unique(m_indexes.begin(), m_indexes.end()), m_indexes.end());
}
