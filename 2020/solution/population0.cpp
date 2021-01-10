#include "population0.hpp"

void Population0::examine() {
    for (auto &i : m_entities) {
        i.examine(m_slices);
    }

    // m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(), [this](const auto &e) {
    //     return e.score() > m_max;
    // }), m_entities.end());
}

void Population0::sort() {
    std::sort(m_entities.begin(), m_entities.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.score() > rhs.score();
    });
}

void Population0::filter() {
    m_entities.resize(m_entities.size() / 3);

    // if (m_entities.size() ^ 1) {
    //     m_entities.pop_back();
    // }
}

void Population0::crossover() {
    m_entities.insert(m_entities.end(), m_entities.begin(), m_entities.end());

    for (int i = 0, j = m_entities.size() / 2; i < j; i += 2) {
        m_entities[i].crossover(m_entities[i + 1]);
    }
}

void Population0::mutation() {
    m_entities.insert(m_entities.end(), m_entities.begin() + m_entities.size() / 2, m_entities.end());

    for (int i = 2 * m_entities.size() / 3, j = m_entities.size(); i < j; ++i) {
        m_entities[i].mutation();
    }
}

void Population0::generate() {
    std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> uid(0, m_slices.size());

    for (int i = 0; i < 15000; ++i) {
        Indexes indexes(m_slices.size());
        std::iota(indexes.begin(), indexes.end(), 0);

        int to_delete = uid(mt);
        for (int i = 0; i < to_delete; ++i) {
            indexes.erase(indexes.begin() + (mt() % indexes.size()));
        }

        // std::reverse(indexes.begin(), indexes.end());
        m_entities.emplace_back(std::move(indexes));
    }
}

void Population0::algorithm() {
    std::cout << "Start!" << std::endl;

    for (int i = 0; i < 10000; ++i) {
        examine();
        sort();

        auto pos = std::lower_bound(m_entities.begin(), m_entities.end(), m_max, [](const auto &e, int val) {
            return e.score() > val;
        });
        ++m_age;

        if (pos->score() == m_max) {
            print(pos);
            break;
        }

        filter();
        crossover();
        mutation();
    }
}

void Population0::print(std::vector<Entity>::iterator it) {
    if (it != m_entities.end()) {
        std::cout << "Age: " << m_age << " - Score: " << it->score() << std::endl;

        for (auto i : it->indexes()) {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }
}
