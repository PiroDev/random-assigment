#include <iostream>
#include <string>
#include <vector>
#include "../inc/input_output.h"
#include "../inc/status_codes.h"
#include "../inc/hashing.h"

int main(int argc, char **argv)
{
    status_code result = ok;

    uint32_t count_variants = 0;
    int64_t seed = 0;
    std::string fname;

    result = get_options(argc, argv, fname, count_variants, seed);

    if (!result)
    {
        std::vector<std::string> students;
        result = read_students(fname, students);

        if (!result)
        {
            std::vector<uint32_t> variants = get_variants(students, count_variants, seed);
            print_variants_assigment(students, variants);
        }
    }

    if (result)
        print_error(result);

    return result;
}
