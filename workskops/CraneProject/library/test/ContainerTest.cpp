//
// Created by Oleksii Budzinskyi on 04/11/2023.
//
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "Container.h"

BOOST_AUTO_TEST_SUITE(ContainerTestSuite)

    BOOST_AUTO_TEST_CASE(testContainer_onlyRegistrationNumber_allWeightsShouldBeZero) {
        Container container(234);
        BOOST_REQUIRE_EQUAL(container.getNumber(), 234);
        BOOST_REQUIRE_EQUAL(container.getTare(), 0.0);
        BOOST_REQUIRE_EQUAL(container.getStrength(), 0.0);
        BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 0.0);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0.0);
        BOOST_REQUIRE_CLOSE_FRACTION(container.getGrossWeight(), 0.0, 0.00001);
    }

    BOOST_AUTO_TEST_CASE(testContainer_noRegistrationNumber_allWeightsShouldBeZero) {
        Container container;
        BOOST_REQUIRE_EQUAL(container.getNumber(), 0);
        BOOST_REQUIRE_EQUAL(container.getTare(), 0.0);
        BOOST_REQUIRE_EQUAL(container.getStrength(), 0.0);
        BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 0.0);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0.0);
    }

    BOOST_AUTO_TEST_CASE(testContainer_setNormalValues_valuesShouldBeSet) {
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        container.setStrength(1000.0);
        BOOST_REQUIRE_EQUAL(container.getTare(), 10.0);
        BOOST_REQUIRE_EQUAL(container.getStrength(), 1000.0);
        BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 100.0);
    }

    BOOST_AUTO_TEST_CASE(testContainer_loadWeightBelowMax_checkNetWeight){
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        container.setStrength(1000.0);
        container.loadCargo(50.0);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 50.0);
        BOOST_REQUIRE_EQUAL(container.getGrossWeight(), 60.0);
    }

    BOOST_AUTO_TEST_CASE(testContainer_loadWeightOverMax_requireException) {
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        BOOST_REQUIRE_THROW(container.loadCargo(150.0), std::runtime_error);

        try {
            container.loadCargo(150.0);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Cargo weight limit exceeded");
        }

    }

    BOOST_AUTO_TEST_CASE(testContainer_unloadWeightOverMin_checkNetWeight) {
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        container.loadCargo(50.0);
        container.unloadCargo(20.0);
        BOOST_REQUIRE_EQUAL(container.getNetWeight(), 30.0);
        BOOST_REQUIRE_EQUAL(container.getGrossWeight(), 40.0);
    }

    BOOST_AUTO_TEST_CASE(testContainer_unloadWeightBelowMin_requireException) {
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        container.loadCargo(50.0);
        BOOST_REQUIRE_THROW(container.unloadCargo(60.0), std::runtime_error);

        try {
            container.unloadCargo(60.0);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Can't unload more than the cargo weights");
        }
    }



    // EXTRA TEST CASES



    BOOST_AUTO_TEST_CASE(testContainer_changeRegulationsWhichAreViolatedByCurrentLoad_requireException) {
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        container.loadCargo(50.0);
        BOOST_REQUIRE_THROW(container.setMaxWeight(40.0);, std::runtime_error);

        try{
            container.setMaxWeight(40.0);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Max weight can't be less than current weight of container and cargo");
        }
    }

    BOOST_AUTO_TEST_CASE(testContainer_changeTareWeightWhichViolatesRegulations_requireException) {
        Container container(234);
        container.setMaxWeight(100.0);
        container.setTare(10.0);
        container.loadCargo(50.0);
        BOOST_REQUIRE_THROW(container.setTare(60.0), std::runtime_error);

        try{
            container.setTare(60.0);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Tare weight can't be more than max weight of container with a load");
        }
    }


BOOST_AUTO_TEST_SUITE_END()