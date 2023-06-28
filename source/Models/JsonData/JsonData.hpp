//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_JSONDATA_HPP
#define CLINKER_VISUALISER_JSONDATA_HPP

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Data.hpp"

namespace json_data {
    struct JsonData {
        Data data;
    };
}

namespace json_data {
    inline void from_json(const json &j, JsonData &x) {
        x.data = j.at("data").get<Data>();
    }

    inline void to_json(json &j, const JsonData &x) {
        j = json::object();
        j["data"] = x.data;
    }
}

#endif //CLINKER_VISUALISER_JSONDATA_HPP
