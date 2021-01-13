#include "population.hpp"

Population::Population(
    std::unique_ptr<Crossover> crossover,
    std::unique_ptr<Generator> generator,
    std::unique_ptr<Mutation> mutation,
    std::unique_ptr<Filter> filter,
    std::unique_ptr<Search> search,
    std::unique_ptr<Sort> sort)
: m_crossover(std::move(crossover))
, m_generator(std::move(generator))
, m_mutation(std::move(mutation))
, m_filter(std::move(filter))
, m_search(std::move(search))
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

Population &Population::set_crossover(std::unique_ptr<Crossover> crossover) {
    m_crossover = std::move(crossover);
    return *this;
}

Population &Population::set_generator(std::unique_ptr<Generator> generator) {
    m_generator = std::move(generator);
    return *this;
}

Population &Population::set_mutation(std::unique_ptr<Mutation> mutation) {
    m_mutation = std::move(mutation);
    return *this;
}

Population &Population::set_filter(std::unique_ptr<Filter> filter) {
    m_filter = std::move(filter);
    return *this;
}

Population &Population::set_search(std::unique_ptr<Search> search) {
    m_search = std::move(search);
    return *this;
}

Population &Population::set_sort(std::unique_ptr<Sort> sort) {
    m_sort = std::move(sort);
    return *this;
}

void Population::input(const char *file) {
    m_file = file;
    m_file.replace(m_file.rfind('.'), 3, ".out");
    m_file.replace(m_file.find("in"), 2, "out");

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

void Population0::algorithm(std::size_t iterations) {
    m_entities = m_generator->generate(m_slices.size());

    Entities::iterator pos = m_entities.end();
    examine();
    m_sort->sort(m_entities);

    for (std::size_t i = 0; i < iterations; ++i) {
        ++m_age;
        pos = m_search->search(m_entities);

        if (pos != m_entities.end() && pos->score() == m_max) {
            print(pos);
            return;
        }
        // std::cout << "FRN: " << m_entities.front().score() << '\n';

        m_filter->filter(m_entities);

        auto temp0 = m_crossover->crossover(m_entities);
        m_entities.insert(m_entities.end(), std::make_move_iterator(temp0.begin()), std::make_move_iterator(temp0.end()));

        auto temp1 = m_mutation->mutation(m_entities);
        m_entities.insert(m_entities.end(), std::make_move_iterator(temp1.begin()), std::make_move_iterator(temp1.end()));

        examine();
        m_sort->sort(m_entities);
    }
    print(m_search->search(m_entities));
}

void Population0::print(std::vector<Entity>::iterator it) {
    if (it != m_entities.end()) {
        std::cout << "Age: " << m_age << " - Score: " << it->score() << std::endl;

        if (std::ofstream ofile(m_file); ofile) {
            // std::cout << "File: " << m_file << std::endl;
            auto &indexes = it->indexes();
            ofile << std::accumulate(indexes.begin(), indexes.end(), 0) << '\n';

            for (std::size_t i = 0, j = indexes.size(); i < j; ++i) {
                if (indexes[i]) {
                    ofile << i << ' ';
                }
            }
        } else {
            std::cout << "WTF!!!" << std::endl;
        }
    } else {
        std::cout << "END" << std::endl;
    }
}
