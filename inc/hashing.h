#ifndef __HASHING_H__
#define __HASHING_H__

#include <cstddef>
#include <vector>
#include <string>

std::vector<uint32_t> get_variants(std::vector<std::string>, uint32_t, int64_t);
uint32_t get_fixed_size_hash(uint32_t, uint32_t);
uint32_t change_hash(uint32_t, int64_t);

#endif