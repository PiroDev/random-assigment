#ifndef __INPUT_OUTPUT_H__
#define __INPUT_OUTPUT_H__

#include <string>
#include <vector>
#include "status_codes.h"

#define END_OF_OPTIONS -1

status_code get_options(int, char **, std::string &, uint32_t &, int64_t &);
void print_help(void);
status_code read_students(std::string, std::vector<std::string> &);
void print_variants_assigment(std::vector<std::string>, std::vector<uint32_t>);
void print_error(status_code);

#endif