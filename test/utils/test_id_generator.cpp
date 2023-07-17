#include "id_generator.h"

#include <unordered_set>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace modoo::core::utils;
#define LOOP_COUNT 10000

TEST_CASE("IdGenerator", "core::utils") {
    SECTION( "check id duplication" )
    {
        std::unordered_set<int> checkSet;

        for (unsigned int i = 0; i < LOOP_COUNT; ++i) {
            int id = IdGenerator::getInstance().createId();
            auto hasDuplicatedId = checkSet.find(id) != checkSet.end();

            REQUIRE(!hasDuplicatedId);

            if (hasDuplicatedId) {
                break;
            } else {
                checkSet.insert(id);
            }
        }
    }
}