//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_GROUP_HPP
#define CLINKER_VISUALISER_GROUP_HPP

#include <string>
#include <vector>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"

namespace json_data {
    struct Group {
        std::string uid;
        std::string label;
        std::vector<std::string> genes;
        bool hidden;
        std::string colour;
    };
}

namespace json_data {
    inline void from_json(const json &j, Group &x) {
        x.uid = j.at("uid").get<std::string>();
        x.label = j.at("label").get<std::string>();
        x.genes = j.at("genes").get<std::vector<std::string>>();
        x.hidden = j.at("hidden").get<bool>();
        x.colour = j.at("colour").get<std::string>();
    }

    inline void to_json(json &j, const Group &x) {
        j = json::object();
        j["uid"] = x.uid;
        j["label"] = x.label;
        j["genes"] = x.genes;
        j["hidden"] = x.hidden;
        j["colour"] = x.colour;
    }
}

#endif //CLINKER_VISUALISER_GROUP_HPP
