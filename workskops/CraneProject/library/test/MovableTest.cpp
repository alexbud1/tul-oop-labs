//
// Created by Oleksii Budzinskyi on 25/11/2023.
//

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "MovableAbstract.h"

BOOST_AUTO_TEST_SUITE(MovableTestSuite)

    BOOST_AUTO_TEST_CASE(testMovableAbstract_Constructor_checkDefalutPosition) {
        MovableAbstract movable(5, 2);
        BOOST_REQUIRE_EQUAL(movable.getPosition(), -1);
    }

    BOOST_AUTO_TEST_CASE(testMovableAbstract_Constructor_checkForward) {
        MovableAbstract movable(5, 2);
        movable.forward(1);
        BOOST_REQUIRE_EQUAL(movable.getPosition(), 0);
    }

    BOOST_AUTO_TEST_CASE(testMovableAbstract_Constructor_checkBackward) {
        MovableAbstract movable(5, 2);
        movable.backward(1);
        BOOST_REQUIRE_EQUAL(movable.getPosition(), -2);
    }

    BOOST_AUTO_TEST_CASE(testMovableAbstract_Constructor_checkForwardLimit) {
        MovableAbstract movable(5, 2);
        movable.forward(1);
        movable.forward(1);
        movable.forward(1);
        movable.forward(1);
        movable.forward(1);
        BOOST_REQUIRE_THROW(movable.forward(1), std::runtime_error);

        try{
            movable.forward(1);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is out of range");
        }
    }

    BOOST_AUTO_TEST_CASE(testMovableAbstract_Constructor_checkBackwardLimit) {
        MovableAbstract movable(5, 2);
        movable.backward(1);

        BOOST_REQUIRE_THROW(movable.backward(1), std::runtime_error);

        try{
            movable.backward(1);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is out of range");
        }
    }

    BOOST_AUTO_TEST_CASE(testMovableAbstract_Constructor_setPosition) {
        MovableAbstract movable(5, 2);
        movable.setPosition(3);
        BOOST_REQUIRE_EQUAL(movable.getPosition(), 3);
    }

    BOOST_AUTO_TEST_CASE(testMovableAbstract_setInvalidPosition_shouldThrowException) {
        MovableAbstract movable(5, 2);
        BOOST_REQUIRE_THROW(movable.setPosition(6), std::runtime_error);

        try{
            movable.setPosition(6);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is out of range");
        }
    }

BOOST_AUTO_TEST_SUITE_END()
