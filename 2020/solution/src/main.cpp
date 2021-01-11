#include "population.hpp"

int main(int ac, char **av) try {
    if (ac == 2) {
        std::unique_ptr<Population> p0 = std::make_unique<Population0>(
            std::make_unique<Crossover0>(),
            std::make_unique<Generator0>(),
            std::make_unique<Mutation0>(),
            std::make_unique<Sort0>());

        p0->input(av[1]);
        p0->algorithm();
    } else {
        std::cerr << "Usage: ./app [file_name]" << std::endl;
    }
} catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
} catch (...) {
    std::cerr << "Uncaught exception" << std::endl;
}
