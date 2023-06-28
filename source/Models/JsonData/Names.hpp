//
// Created by Florian Claisse on 27/06/2023.
//

#ifndef CLINKER_VISUALISER_NAMES_HPP
#define CLINKER_VISUALISER_NAMES_HPP

#include <optional>
#include <string>

#include "../include/json+extensions.hpp"

#include "Helper.hpp"

namespace json_data {
    struct Names {
        std::optional<std::string> gene;
        std::string locus_tag;
        std::string inference;
        std::string codon_start;
        std::string transl_table;
        std::string product;
    };
}

namespace json_data {
    inline void from_json(const json &j, Names &x) {
        x.gene = get_stack_optional<std::string>(j, "gene");
        x.locus_tag = j.at("locus_tag").get<std::string>();
        x.inference = j.at("inference").get<std::string>();
        x.codon_start = j.at("codon_start").get<std::string>();
        x.transl_table = j.at("transl_table").get<std::string>();
        x.product = j.at("product").get<std::string>();
    }

    inline void to_json(json &j, const Names &x) {
        j = json::object();
        j["gene"] = x.gene;
        j["locus_tag"] = x.locus_tag;
        j["inference"] = x.inference;
        j["codon_start"] = x.codon_start;
        j["transl_table"] = x.transl_table;
        j["product"] = x.product;
    }
}

#endif //CLINKER_VISUALISER_NAMES_HPP
