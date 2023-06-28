//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_LINK_HPP
#define CLINKER_VISUALISER_LINK_HPP

#include <string>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Query.hpp"

namespace json_data {
    struct Link {
        std::string uid;
        Query query;
        Query target;
        int64_t identity;
        int64_t similarity;
    };
}

namespace json_data {
    inline void from_json(const json &j, Link &x) {
        x.uid = j.at("uid").get<std::string>();
        x.query = j.at("query").get<Query>();
        x.target = j.at("target").get<Query>();
        x.identity = j.at("identity").get<int64_t>();
        x.similarity = j.at("similarity").get<int64_t>();
    }

    inline void to_json(json &j, const Link &x) {
        j = json::object();
        j["uid"] = x.uid;
        j["query"] = x.query;
        j["target"] = x.target;
        j["identity"] = x.identity;
        j["similarity"] = x.similarity;
    }
}

#endif //CLINKER_VISUALISER_LINK_HPP
