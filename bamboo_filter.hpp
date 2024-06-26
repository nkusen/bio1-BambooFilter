#ifndef BAMBOO_FILTER_HPP
#define BAMBOO_FILTER_HPP

#include "segment.hpp"
#include <vector>
#include <string>

class BambooFilter
{
public:
    BambooFilter();
    ~BambooFilter();

    bool insert(const std::string &element);
    bool lookup(const std::string &element) const;
    bool remove(const std::string &element);

private:
    bool insert_hash(const uint32_t &hash_val);
    bool lookup_hash(const uint32_t &hash_val) const;
    bool remove_hash(const uint32_t &hash_val);

    void expand();
    void compress();

    uint32_t hash(const std::string &element) const;
    uint32_t get_segment_index(uint32_t hash_value) const;

    std::vector<Segment *> segments_;
    uint32_t elements_count_;
    uint32_t current_segment_index_;
    uint32_t expansion_round_;
    uint32_t expansion_threshold_;
    uint32_t compression_threshold_;
};

#endif // BAMBOO_FILTER_HPP
