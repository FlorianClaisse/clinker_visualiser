//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_QUERY_HPP
#define CLINKER_VISUALISER_QUERY_HPP

#include <string>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Names.hpp"

namespace json_data {
    struct Query {
        std::string uid;
        std::string label;
        Names names;
        int64_t start;
        int64_t end;
        int64_t strand;
        std::string sequence;
        std::string translation;
    };
}

namespace json_data {
    inline void from_json(const json &j, Query &x) {
        x.uid = j.at("uid").get<std::string>();
        x.label = j.at("label").get<std::string>();
        x.names = j.at("names").get<Names>();
        x.start = j.at("start").get<int64_t>();
        x.end = j.at("end").get<int64_t>();
        x.strand = j.at("strand").get<int64_t>();
        x.sequence = j.at("sequence").get<std::string>();
        x.translation = j.at("translation").get<std::string>();
    }

    inline void to_json(json &j, const Query &x) {
        j = json::object();
        j["uid"] = x.uid;
        j["label"] = x.label;
        j["names"] = x.names;
        j["start"] = x.start;
        j["end"] = x.end;
        j["strand"] = x.strand;
        j["sequence"] = x.sequence;
        j["translation"] = x.translation;
    }
}

#endif //CLINKER_VISUALISER_QUERY_HPP
