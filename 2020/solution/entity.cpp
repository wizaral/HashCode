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

    for (int i : m_indexes) {
        m_score += slices[i];
    }
}

void Entity::validate() {
    std::sort(m_indexes.begin(), m_indexes.end());
    m_indexes.erase(std::unique(m_indexes.begin(), m_indexes.end()), m_indexes.end());
}

void Entity::crossover(Entity &entity) {
    if (m_indexes.size() < entity.m_indexes.size()) {
        std::swap_ranges(
            m_indexes.begin(),
            m_indexes.begin() + m_indexes.size() / 2,
            entity.m_indexes.begin()
        );
    } else {
        std::swap_ranges(
            entity.m_indexes.begin(),
            entity.m_indexes.begin() + entity.m_indexes.size() / 2,
            m_indexes.begin()
        );
    }

    // validate();
    // entity.validate();
}

void Entity::mutation() {
    // ...
}
