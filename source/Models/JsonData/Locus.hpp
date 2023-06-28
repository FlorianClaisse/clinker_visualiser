//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_LOCUS_HPP
#define CLINKER_VISUALISER_LOCUS_HPP

#include <string>
#include <vector>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Gene.hpp"

namespace json_data {
    struct Locus {
        std::string uid;
        std::string name;
        int64_t locus_start;
        int64_t locus_end;
        std::vector<Gene> genes;
        int64_t start;
        int64_t end;
        int64_t offset;
        std::string cluster;
        bool flipped;
        nlohmann::json trim_left;
        nlohmann::json trim_right;
    };
}

namespace json_data {
    inline void from_json(const json &j, Locus &x) {
        x.uid = j.at("uid").get<std::string>();
        x.name = j.at("name").get<std::string>();
        x.locus_start = j.at("start").get<int64_t>();
        x.locus_end = j.at("end").get<int64_t>();
        x.genes = j.at("genes").get<std::vector<Gene>>();
        x.start = j.at("_start").get<int64_t>();
        x.end = j.at("_end").get<int64_t>();
        x.offset = j.at("_offset").get<int64_t>();
        x.cluster = j.at("_cluster").get<std::string>();
        x.flipped = j.at("_flipped").get<bool>();
        x.trim_left = get_untyped(j, "_trimLeft");
        x.trim_right = get_untyped(j, "_trimRight");
    }

    inline void to_json(json &j, const Locus &x) {
        j = json::object();
        j["uid"] = x.uid;
        j["name"] = x.name;
        j["start"] = x.locus_start;
        j["end"] = x.locus_end;
        j["genes"] = x.genes;
        j["_start"] = x.start;
        j["_end"] = x.end;
        j["_offset"] = x.offset;
        j["_cluster"] = x.cluster;
        j["_flipped"] = x.flipped;
        j["_trimLeft"] = x.trim_left;
        j["_trimRight"] = x.trim_right;
    }
}

#endif //CLINKER_VISUALISER_LOCUS_HPP
