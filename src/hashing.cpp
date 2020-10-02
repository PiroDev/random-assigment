#include "../inc/hashing.h"

std::vector<uint32_t> get_variants(std::vector<std::string> students, uint32_t count_variants, int64_t seed)
{
    std::vector<uint32_t> variants;
    uint32_t variant;
    std::hash<std::string> hash_string;

    for (auto student : students)
    {
        variant = (uint32_t) hash_string(student);
        variant = change_hash(variant, seed);
        variant = get_fixed_size_hash(variant, count_variants) + 1;
        variants.push_back(variant);
    }

    return variants;
}

uint32_t get_fixed_size_hash(uint32_t hashed, uint32_t size)
{
    return hashed % size;
}

uint32_t change_hash(uint32_t hashed, int64_t seed)
{
    return hashed xor seed;
}