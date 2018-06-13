#include "Discreture/LexCombinations.hpp"
#include <cstdlib>
#include <sstream>
#include <string>

int n = 5; // Global variable for exposition purposes. Do not use global
           // variables in real code.
int k = 3;

using std::cout;
using std::endl;
using dscr::lex_combinations;
using dscr::operator<<;

// Just sets global variables n and k.
void parse_command_line(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false); // this makes terminal output a bit
                                           // faster.

    parse_command_line(argc, argv);

    for (auto& x : lex_combinations(n, k))
        cout << x << endl;

    return 0;
}

void parse_command_line(int argc, char* argv[])
{
    std::stringstream usage;
    usage << "Usage: lex_combinations n k\n"
          << "Print to STDOUT the set of combinations of size k of a subset of "
             "size n,\n"
          << "where n and k are integers, in lexicographic order.\n"
          << "Example:\n"
          << "./lex_combinations"
          << " " << n << " " << k << "\n";

    if (argc != 3)
    {
        cout << "Wrong number of arguments!\n";
        cout << usage.str();
        return;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    try
    {
        int ntemp = std::stoi(arguments[0]);
        int ktemp = std::stoi(arguments[1]);

        if (ktemp < 0)
            throw;
        // only set if there were no errors
        n = ntemp;
        k = ktemp;
    }
    catch (...)
    {
        cout << "Arguments must be numbers!\n";
        cout << usage.str();
        return;
    }
}
