//
// Created by Oleksii Budzinskyi on 25/11/2023.
//

#include "Truck.h"
#include <stdexcept>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TruckTestSuite)

    BOOST_AUTO_TEST_CASE(testTruck_emptyConstructor_sizeShouldBeZero) {
        Truck truck;
        BOOST_REQUIRE_EQUAL(truck.getSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(testTruck_giveOneContainer_sizeShouldBeOne) {
        Truck truck;
        Container container(234);
        truck.give(container);
        BOOST_REQUIRE_EQUAL(truck.getSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(testTruck_giveThreeContainers_shouldThrowException) {
        Truck truck;
        Container container(234);
        Container container1(235);
        Container container2(236);
        truck.give(container);
        truck.give(container1);
        BOOST_CHECK_THROW(truck.give(container2), std::runtime_error);

        try{
            truck.give(container2);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Truck is full");
        }
    }

    BOOST_AUTO_TEST_CASE(testTruck_takeOneContainer_sizeShouldBeZero) {
        Truck truck;
        Container container(234);
        truck.give(container);
        truck.take();
        BOOST_REQUIRE_EQUAL(truck.getSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(testTruck_takeOneContainer_shouldThrowException) {
        Truck truck;
        BOOST_CHECK_THROW(truck.take(), std::runtime_error);

        try{
            truck.take();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Truck is empty");
        }
    }

    BOOST_AUTO_TEST_CASE(testTruck_getCapacity_shouldBeTwo) {
        Truck truck;
        BOOST_REQUIRE_EQUAL(truck.getCapacity(), TRUCK_CAPACITY);
    }

    BOOST_AUTO_TEST_CASE(testTruck_atIndexZero_shouldBeEmpty) {
        Truck truck;
        BOOST_REQUIRE_EQUAL(truck.at(0).getNumber(), 0);
    }

    BOOST_AUTO_TEST_CASE(testTruck_atIndexZero_shouldBeNotEmpty) {
        Truck truck;
        Container container(234);
        truck.give(container);
        BOOST_REQUIRE_EQUAL(truck.at(0).getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testTruck_atInvalidIndex_shouldThrowException) {
        Truck truck;
        BOOST_CHECK_THROW(truck.at(5), std::runtime_error);

        try{
            truck.at(5);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Index is out of range");
        }
    }



BOOST_AUTO_TEST_SUITE_END()