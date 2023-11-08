//
// Created by Oleksii Budzinskyi on 08/11/2023.
//

#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "ContainerStack.h"

BOOST_AUTO_TEST_SUITE(ContainerStackTestSuite)

    BOOST_AUTO_TEST_CASE(testContainerStack_emptyConstructor_sizeShouldBeZero) {
        ContainerStack stack;
        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_giveOneContainer_sizeShouldBeOne) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);
        BOOST_REQUIRE_EQUAL(stack.getSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_giveThreeContainers_checkCapacity) {
        ContainerStack stack;
        Container container(234);
        Container container1(235);
        Container container2(236);
        stack.give(container);
        stack.give(container1);
        stack.give(container2);
        BOOST_REQUIRE_EQUAL(stack.getSize(), 3);
        BOOST_REQUIRE_LE(stack.getSize(), stack.getCapacity());
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_giveMoreThanCapacity_requireException) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);
        stack.give(container);

        BOOST_REQUIRE_THROW(stack.give(container);, std::runtime_error);

        try{
            stack.give(container);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Stack is full");
        }
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_takeOneContainer_sizeShouldBeZero) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);
        stack.take();
        BOOST_REQUIRE_EQUAL(stack.getSize(), 0);
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_takeFromEmptyStack_requireException) {
        ContainerStack stack;
        BOOST_REQUIRE_THROW(stack.take();, std::runtime_error);

        try{
            stack.take();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Stack is empty");
        }
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_atOneContainer_checkNumber) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);
        BOOST_REQUIRE_EQUAL(stack.at(0).getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_atOneContainer_requireException) {
        ContainerStack stack;
        Container container(234);
        BOOST_REQUIRE_THROW(stack.at(0);, std::runtime_error);

        try{
            stack.at(0);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Height is out of range");
        }
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_removeOneContainer_fromThreeContainersStack_checkNumber) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);
        Container container1(235);
        stack.give(container1);
        Container container2(236);
        stack.give(container2);

        stack.take();
        BOOST_REQUIRE_EQUAL(stack.at(0).getNumber(), 234);
        BOOST_REQUIRE_EQUAL(stack.at(1).getNumber(), 235);
        BOOST_REQUIRE_EQUAL(stack.getSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_addThreeContainers_checkOrder) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);
        Container container1(235);
        stack.give(container1);
        Container container2(236);
        stack.give(container2);

        BOOST_REQUIRE_EQUAL(stack.at(0).getNumber(), 234);
        BOOST_REQUIRE_EQUAL(stack.at(1).getNumber(), 235);
        BOOST_REQUIRE_EQUAL(stack.at(2).getNumber(), 236);
        BOOST_REQUIRE_EQUAL(stack.getSize(), 3);
    }

    BOOST_AUTO_TEST_CASE(testContainerStack_tryReachingUnapropriatePositionWithAt_requireException) {
        ContainerStack stack;
        Container container(234);
        stack.give(container);

        BOOST_REQUIRE_THROW(stack.at(1);, std::runtime_error);
        BOOST_REQUIRE_THROW(stack.at(-1);, std::runtime_error);

        try{
            stack.at(1);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Height is out of range");
        }

    }

BOOST_AUTO_TEST_SUITE_END()