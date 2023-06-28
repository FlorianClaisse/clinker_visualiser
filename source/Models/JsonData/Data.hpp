//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_DATA_HPP
#define CLINKER_VISUALISER_DATA_HPP

#include <vector>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Cluster.hpp"
#include "Link.hpp"
#include "Group.hpp"

namespace json_data {
    struct Data {
        std::vector<Cluster> clusters;
        std::vector<Link> links;
        std::vector<Group> groups;
    };
}

namespace json_data {
    inline void from_json(const json &j, Data &x) {
        x.clusters = j.at("clusters").get<std::vector<Cluster>>();
        x.links = j.at("links").get<std::vector<Link>>();
        x.groups = j.at("groups").get<std::vector<Group>>();
    }

    inline void to_json(json &j, const Data &x) {
        j = json::object();
        j["clusters"] = x.clusters;
        j["links"] = x.links;
        j["groups"] = x.groups;
    }
}

#endif //CLINKER_VISUALISER_DATA_HPP
