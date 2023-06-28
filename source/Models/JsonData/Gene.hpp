//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_GENE_HPP
#define CLINKER_VISUALISER_GENE_HPP

#include <string>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"
#include "Names.hpp"

namespace json_data {
    struct Gene {
        std::string uid;
        std::string label;
        Names names;
        int64_t gene_start;
        int64_t gene_end;
        int64_t gene_strand;
        std::string sequence;
        std::string translation;
        std::string locus;
        std::string cluster;
        int64_t start;
        int64_t end;
        int64_t strand;
    };
}

namespace json_data {
    inline void from_json(const json &j, Gene &x) {
        x.uid = j.at("uid").get<std::string>();
        x.label = j.at("label").get<std::string>();
        x.names = j.at("names").get<Names>();
        x.gene_start = j.at("start").get<int64_t>();
        x.gene_end = j.at("end").get<int64_t>();
        x.gene_strand = j.at("strand").get<int64_t>();
        x.sequence = j.at("sequence").get<std::string>();
        x.translation = j.at("translation").get<std::string>();
        x.locus = j.at("_locus").get<std::string>();
        x.cluster = j.at("_cluster").get<std::string>();
        x.start = j.at("_start").get<int64_t>();
        x.end = j.at("_end").get<int64_t>();
        x.strand = j.at("_strand").get<int64_t>();
    }

    inline void to_json(json &j, const Gene &x) {
        j = json::object();
        j["uid"] = x.uid;
        j["label"] = x.label;
        j["names"] = x.names;
        j["start"] = x.gene_start;
        j["end"] = x.gene_end;
        j["strand"] = x.gene_strand;
        j["sequence"] = x.sequence;
        j["translation"] = x.translation;
        j["_locus"] = x.locus;
        j["_cluster"] = x.cluster;
        j["_start"] = x.start;
        j["_end"] = x.end;
        j["_strand"] = x.strand;
    }
}

#endif //CLINKER_VISUALISER_GENE_HPP
