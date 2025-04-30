#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE( romanos_para_decimal("V") == 5 );
    REQUIRE( romanos_para_decimal("X") == 10 );
    REQUIRE( romanos_para_decimal("L") == 50 );
    REQUIRE( romanos_para_decimal("C") == 100 );
    REQUIRE( romanos_para_decimal("D") == 500 );
    REQUIRE( romanos_para_decimal("M") == 1000 );
}

TEST_CASE( "Numeros romanos - algarismos invalidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    REQUIRE( romanos_para_decimal("i") == -1 );
    REQUIRE( romanos_para_decimal("qwe") == -1 );
    REQUIRE( romanos_para_decimal("XXXX") == -1 );
    REQUIRE( romanos_para_decimal("VV") == -1 );
    REQUIRE( romanos_para_decimal("VX") == -1 );
    REQUIRE( romanos_para_decimal("LC") == -1 );
    REQUIRE( romanos_para_decimal("DM") == -1 );
}

TEST_CASE("Numeros romanos - compostos", "[romanos]") {
    REQUIRE(romanos_para_decimal("XIV") == 14);
    REQUIRE(romanos_para_decimal("XCIX") == 99);
    REQUIRE(romanos_para_decimal("MCMXCIV") == 1994);
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("III") == 3);
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("VI") == 6);
    REQUIRE(romanos_para_decimal("VII") == 7);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XII") == 12);
}