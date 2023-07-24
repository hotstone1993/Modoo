#include "base_layer.h"

#include <iostream>
#include <string>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("BaseContext", "core") {
    SECTION( "Initialization test" )
    {
        modoo::core::BaseContext context;
    }
}