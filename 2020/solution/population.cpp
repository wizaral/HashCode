#include "population.hpp"

Population::Population(Slices &&slices)
: m_slices(std::move(slices)) {}

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
    if (std::ifstream ifile(file); ifile) {
        int temp;
        ifile >> m_max >> temp;
        m_slices.resize(temp);

        for (auto &i : m_slices) {
            ifile >> i;
        }

        // std::cout << "Max: " << m_max << '\n';
        // for (auto i : m_slices) {
        //     std::cout << i << ' ';
        // }
        // std::cout << std::endl;
    } else {
        throw std::invalid_argument("Wrong file name");
    }
}
