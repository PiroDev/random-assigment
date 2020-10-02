#include "../inc/input_output.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <getopt.h>

bool all_options_recieved(std::vector<bool>);

status_code get_options(int argc, char **argv, std::string &fname, uint32_t &count_variants, int64_t &seed)
{
    status_code result = ok;

    const struct option options[] = {
        { "file", required_argument, nullptr, 0 },
        { "numbilets", required_argument, nullptr, 1 },
        { "param", required_argument, nullptr, 2 },
        { nullptr, no_argument, nullptr, 0 }
    };

    std::vector<bool> flags = { false, false, false };

    int opts_count = 3;

    opterr = 0;

    int opt_index = 0;
    int opt = getopt_long(argc, argv, "", options, &opt_index);

    while ((opt != END_OF_OPTIONS) && (!result))
    {
        if (opt == 0)
        {
            fname = std::string(optarg);
            flags[0] = true;
        }
        else if (opt == 1)
        {
            std::istringstream iss (optarg);
            int64_t temp = 0;
            iss >> temp;
            if (iss.fail() || temp <= 0)
                result = error_wrong_option_value;
            else
            {
                count_variants = (uint32_t) temp;
                flags[1] = true;
            }
        }
        else if (opt == 2)
        {
            std::istringstream iss (optarg);
            iss >> seed;
            if (iss.fail())
                result = error_wrong_option_value;
            else
                flags[2] = true;
        }
        else if (opt == '?')
            result = error_unrecognized_option;

        opt = getopt_long(argc, argv, "", options, &opt_index);
    }

    if (!result && (!all_options_recieved(flags) || (opt_index != opts_count - 1)))
        result = error_wrong_options_count;

    return result;
}

bool all_options_recieved(std::vector<bool> flags)
{
    return std::find(flags.begin(), flags.end(), false) == flags.end();
}

void print_help(void)
{
    std::cout << "Использование программы: ";
    std::cout << "./assigment.exe --file <filename> --numbilets <count> --param <seed>" << std::endl;
    std::cout << "<filename> - путь к входному файлу" << std::endl;
    std::cout << "<count> - количество распределяемых вариантов" << std::endl;
    std::cout << "<seed> - параметр распределения (целое число)" << std::endl;
}

status_code read_students(std::string fname, std::vector<std::string> &students)
{
    status_code result = ok;
    std::ifstream file (fname, std::ios::in);

    if (!file.fail())
    {
        std::string buf;

        while (!file.eof())
        {
            std::getline(file, buf);
            students.push_back(buf);
        }

        file.close();
    }
    else
        result = error_cannot_open_input_file;

    return result;
}

void print_variants_assigment(std::vector<std::string> students, std::vector<uint32_t> variants)
{
    for (size_t i = 0; i < students.size(); i++)
        std::cout << students[i] << ": " << variants[i] << std::endl;
}

void print_error(status_code error)
{
    switch (error)
    {
        case error_cannot_open_input_file:
            std::cout << "Ошибка при открытии файла!" << std::endl;
            break;

        case error_unrecognized_option:
            std::cout << "Неверный аргумент при запуске программы!" << std::endl;
            print_help();
            break;

        case error_wrong_option_value:
            std::cout << "Неверное значение параметра при запуске программы!" << std::endl;
            print_help();
            break;
        
        case error_wrong_options_count:
            std::cout << "Неверное количество параметров при запуске программы!" << std::endl;
            print_help();
            break;

        default:
            break;
    }
}