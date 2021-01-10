#include "population0.hpp"

int main(int ac, char **av) try {
    if (ac == 2) {
        Population0 p0;
        p0.input(av[1]);

        p0.generate();
        p0.algorithm();
    } else {
        std::cerr << "Usage: ./app [file_name]" << std::endl;
    }
} catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
} catch (...) {
    std::cerr << "Uncaught exception" << std::endl;
}
