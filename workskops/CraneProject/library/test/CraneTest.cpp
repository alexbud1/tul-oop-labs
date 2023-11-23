//
// Created by Oleksii Budzinskyi on 23/11/2023.
//
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "ContainerStack.h"
#include "Crane.h"
#include "Container.h"

BOOST_AUTO_TEST_SUITE(CraneTestSuite)

    BOOST_AUTO_TEST_CASE(testCrane_positionParked_shouldBeParked) {
        Crane crane;
        crane.park();
        BOOST_REQUIRE_EQUAL(crane.isParked(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCrane_shouldBeLoaded) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.isLoaded(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_notLoadCrane_shouldNotBeLoaded) {
        Crane crane;
        BOOST_REQUIRE_EQUAL(crane.isLoaded(), false);
    }

    BOOST_AUTO_TEST_CASE(testCrane_notLoadCrane_shouldBeUnloaded) {
        Crane crane;
        BOOST_REQUIRE_EQUAL(crane.isUnloaded(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCrane_shouldNotBeUnloaded) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.isUnloaded(), false);
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCrane_shouldBeWaitingFull) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.isWaitingFull(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_notLoadCrane_shouldBeWaitingEmpty) {
        Crane crane;
        BOOST_REQUIRE_EQUAL(crane.isWaitingEmpty(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCrane_shouldNotBeWaitingEmpty) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.isWaitingEmpty(), false);
    }

    BOOST_AUTO_TEST_CASE(testCrane_parkCrane_shouldThrowException) {
        Crane crane;
        crane.park();
        BOOST_REQUIRE_THROW(crane.park(), std::runtime_error);

        try{
            crane.park();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already parked");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_parkCraneLoaded_shouldThrowException) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_THROW(crane.park(), std::runtime_error);

        try{
            crane.park();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is loaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_positionParked_positionShouldBeMinusOne) {
        Crane crane;
        crane.park();
        BOOST_REQUIRE_EQUAL(crane.getPosition(), -1);
    }

    BOOST_AUTO_TEST_CASE(testCrane_toTrailer_positionShouldBeMinusTwo) {
        Crane crane;
        crane.toTrailer();
        BOOST_REQUIRE_EQUAL(crane.getPosition(), -2);
    }

    BOOST_AUTO_TEST_CASE(testCrane_toTrailerBeingNearTrailer_shouldThrowException) {
        Crane crane;
        crane.toTrailer();
        BOOST_REQUIRE_THROW(crane.toTrailer(), std::runtime_error);

        try{
            crane.toTrailer();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already near the trailer");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCraneNotBeingNearTrailer_shouldThrowException) {
        Crane crane;
        Container container(234);
        BOOST_REQUIRE_THROW(crane.load(container), std::runtime_error);

        try{
            crane.load(container);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is not over the trailer");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCraneBeingLoaded_shouldThrowException) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_THROW(crane.load(container), std::runtime_error);

        try{
            crane.load(container);
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already loaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadCrane_checkContainerNumber) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.getContainer().getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testCrane_unloadCraneNotBeingLoaded_shouldThrowException) {
        Crane crane;
        BOOST_REQUIRE_THROW(crane.unload(), std::runtime_error);

        try{
            crane.unload();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already unloaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_unloadCraneNotBeingNearTrailer_shouldThrowException) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        crane.forward(1);
        BOOST_REQUIRE_THROW(crane.unload(), std::runtime_error);

        try{
            crane.unload();
            BOOST_ERROR("Expected std::runtime_error, but no exception was thrown.");
        } catch (const std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is not over the trailer");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_unloadCrane_checkContainerNumber) {
        Crane crane;
        Container container(234);
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.unload().getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testCrane_forwardCrane_checkPosition) {
        Crane crane;
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.forward(1);
        BOOST_REQUIRE_EQUAL(crane.getPosition(), -1);
    }

    BOOST_AUTO_TEST_CASE(testCrane_forwardCrane_checkPositionAfterSeveralSteps) {
        Crane crane;
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.forward(3);
        BOOST_REQUIRE_EQUAL(crane.getPosition(), 1);
    }

    BOOST_AUTO_TEST_CASE(testCrane_forwardCraneToLimit_shouldThrowException) {
        Crane crane;
        crane.toTrailer(); // move crane to trailer at -2 position
        BOOST_REQUIRE_THROW(crane.forward(7), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(testCrane_backwardCrane_checkPosition) {
        Crane crane;
        crane.toTrailer();// move crane to trailer at -2 position
        crane.forward(1);
        crane.backward(1);
        BOOST_REQUIRE_EQUAL(crane.getPosition(), -2);
    }

    BOOST_AUTO_TEST_CASE(testCrane_backwardCraneToLimit_shouldThrowException) {
        Crane crane;
        crane.toTrailer(); // move crane to trailer at -2 position
        BOOST_REQUIRE_THROW(crane.backward(7), std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(testCrane_forwardCrane_checkPositionAfterSeveralStepsAndBackward) {
        Crane crane;
        crane.toTrailer(); // move crane to trailer at -2 position
        crane.forward(3);
        crane.backward(2);
        BOOST_REQUIRE_EQUAL(crane.getPosition(), -1);
    }

    BOOST_AUTO_TEST_CASE(testCrane_pickUpCrane_checkPosition) {
        // Create stack with one container
        ContainerStack stack1;
        Container container(234);
        stack1.give(container);

        // Create crane with stack
        ContainerStack storage[MAX_STACKS];
        storage[0] = stack1;
        Crane crane(-1, storage, Container());

        crane.toTrailer(); // move crane to trailer at -2 position
        crane.forward(2);
        crane.pickUp();
        BOOST_REQUIRE_EQUAL(crane.getPosition(), 0);
    }

    BOOST_AUTO_TEST_CASE(testCrane_pickUpCrane_checkContainerNumber) {
        // Create stack with one container
        ContainerStack stack1;
        Container container(234);
        stack1.give(container);

        // Create crane with stack
        ContainerStack storage[MAX_STACKS];
        storage[0] = stack1;
        Crane crane(-1, storage, Container());

        crane.toTrailer(); // move crane to trailer at -2 position
        crane.forward(2);
        crane.pickUp();
        BOOST_REQUIRE_EQUAL(crane.getContainer().getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testCrane_putDownCrane_checkPosition) {
        // Create stack with one container
        ContainerStack stack1;
        Container container(234);
        stack1.give(container);

        // Create crane with stack
        ContainerStack storage[MAX_STACKS];
        storage[0] = stack1;
        Crane crane(-1, storage, Container());

        crane.toTrailer(); // move crane to trailer at -2 position
        Container container1(235);
        crane.load(container1);
        crane.forward(2);
        crane.putDown();
        BOOST_REQUIRE_EQUAL(crane.getPosition(), 0);
    }

    BOOST_AUTO_TEST_CASE(testCrane_putDownCrane_checkContainerNumber) {
        // Create stack with one container
        ContainerStack stack1;
        Container container(234);
        stack1.give(container);

        // Create crane with stack
        ContainerStack storage[MAX_STACKS];
        storage[0] = stack1;
        Crane crane(-1, storage, Container());

        crane.toTrailer(); // move crane to trailer at -2 position
        Container container1(235);
        crane.load(container1);
        crane.forward(2);
        crane.putDown();
        BOOST_REQUIRE_EQUAL(crane.stackAt(0).at(1).getNumber(), 235);
    }

    BOOST_AUTO_TEST_CASE(testCrane_MoveCrane_checkPosition){
        Crane crane;
        crane.toTrailer();
        BOOST_REQUIRE_EQUAL(crane.getPosition(), -2);
    }

    BOOST_AUTO_TEST_CASE(testCrane_checkContainer){
        Crane crane;
        Container container(234);
        crane.toTrailer();
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.getContainer().getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testCrane_checkStack){
        // Create stack with one container
        ContainerStack stack1;
        Container container(234);
        stack1.give(container);

        // Create crane with stack
        ContainerStack storage[MAX_STACKS];
        storage[0] = stack1;
        Crane crane(-1, storage, Container());

        crane.toTrailer();
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.stackAt(0).at(0).getNumber(), 234);
    }

    BOOST_AUTO_TEST_CASE(testCrane_checkCanPutDown){
        Crane crane;
        Container container(234);
        crane.toTrailer();
        crane.load(container);
        BOOST_REQUIRE_EQUAL(crane.canPutDown(), false);
    }


BOOST_AUTO_TEST_SUITE_END()