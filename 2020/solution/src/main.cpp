#include "population.hpp"

int main(int ac, char **av) try {
    if (ac == 2) {
        std::unique_ptr<Population> p0 = std::make_unique<Population0>();
        p0->input(av[1]);

        p0->set_crossover(std::make_unique<Crossover0>()).
            set_generator(std::make_unique<Generator0>()).
            set_mutation(std::make_unique<Mutation1>(p0->slices().size())).
            set_filter(std::make_unique<Filter0>()).
            set_search(std::make_unique<Search1>()).
            set_sort(std::make_unique<Sort2>(p0->max()));

        p0->algorithm(1000);
    } else {
        std::cerr << "Usage: ./app [file_name]" << std::endl;
    }
} catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
} catch (...) {
    std::cerr << "Uncaught exception" << std::endl;
}
