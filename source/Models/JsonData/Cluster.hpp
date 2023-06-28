//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_CLUSTER_HPP
#define CLINKER_VISUALISER_CLUSTER_HPP

#include <string>
#include <vector>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Locus.hpp"

namespace json_data {
    struct Cluster {
        std::string uid;
        std::string name;
        std::vector<Locus> loci;
        int64_t slot;
    };
}

namespace json_data {
    inline void from_json(const json &j, Cluster &x) {
        x.uid = j.at("uid").get<std::string>();
        x.name = j.at("name").get<std::string>();
        x.loci = j.at("loci").get<std::vector<Locus>>();
        x.slot = j.at("slot").get<int64_t>();
    }

    inline void to_json(json &j, const Cluster &x) {
        j = json::object();
        j["uid"] = x.uid;
        j["name"] = x.name;
        j["loci"] = x.loci;
        j["slot"] = x.slot;
    }
}

#endif //CLINKER_VISUALISER_CLUSTER_HPP
