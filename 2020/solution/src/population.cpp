#include "population.hpp"

Population::Population(
    std::unique_ptr<Crossover> crossover,
    std::unique_ptr<Generator> generator,
    std::unique_ptr<Mutation> mutation,
    std::unique_ptr<Sort> sort)
: m_crossover(std::move(crossover))
, m_generator(std::move(generator))
, m_mutation(std::move(mutation))
, m_sort(std::move(sort)) {}

Slices &Population::slices() {
    return m_slices;
}

Entities &Population::entities() {
    return m_entities;
}

const Slices &Population::slices() const {
    return m_slices;
}

const Entities &Population::entities() const {
    return m_entities;
}

int Population::age() const {
    return m_age;
}

int Population::max() const {
    return m_max;
}

void Population::input(const char *file) {
    m_file = file;
    m_file.replace(m_file.rfind('.'), 3, ".out");

    if (std::ifstream ifile(file); ifile) {
        int temp;
        ifile >> m_max >> temp;
        m_slices.resize(temp);

        for (auto &i : m_slices) {
            ifile >> i;
        }
    } else {
        throw std::invalid_argument("Wrong file name");
    }
}

void Population::examine() {
    for (auto &i : m_entities) {
        i.examine(m_slices);
    }
}

// ================================================================================================================== //

void Population0::filter() {
    // m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(), [this](const auto &e) {
    //     return e.score() > m_max;
    // }), m_entities.end());

    m_entities.resize(m_entities.size() / 4);
}

void Population0::algorithm() {
    std::cout << "Start!" << std::endl;
    m_entities = m_generator->generate(m_slices.size());

    for (std::size_t i = 0; i < 10000ul; ++i) {
        examine();
        m_sort->sort(m_entities);

        auto pos = std::lower_bound(m_entities.begin(), m_entities.end(), m_max, [](const auto &e, int val) {
            return e.score() > val;
        });
        ++m_age;

        if (pos->score() == m_max) {
            std::cout << std::distance(m_entities.begin(), pos) << std::endl;
            print(pos);
            break;
        }

        filter();
        auto temp = m_crossover->crossover(m_entities);
        m_entities.insert(m_entities.end(), temp.begin(), temp.end());

        auto temp1 = m_mutation->mutation(m_entities);
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
