//
// Created by Oleksii Budzinskyi on 23/11/2023.
//
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "ContainerStack.h"
#include "Crane.h"
#include "Container.h"

BOOST_AUTO_TEST_SUITE(CraneTestSuite)

    BOOST_AUTO_TEST_CASE(testCrane_constructor_checkIfCraneIsParked) {
        Crane crane;
        BOOST_CHECK_EQUAL(crane.isParked(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_parkCrane_checkIfCraneIsParked) {
        Crane crane;
        crane.forward(1);
        crane.park();
        BOOST_CHECK_EQUAL(crane.isParked(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_parkParkedCrane_shouldThrowException) {
        Crane crane;

        BOOST_CHECK_THROW(crane.park(), std::runtime_error);

        try {
            crane.park();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already parked");
        }

    }

    BOOST_AUTO_TEST_CASE(testCrane_toTrailer_checkIfCraneIsOverTrailer) {
        Crane crane;
        crane.toTrailer();
        BOOST_CHECK_EQUAL(crane.getPosition(), -TRUCK_CAPACITY);
    }

    BOOST_AUTO_TEST_CASE(testCrane_toTrailerCraneIsOverTrailer_shouldThrowException) {
        Crane crane;
        crane.toTrailer();

        BOOST_CHECK_THROW(crane.toTrailer(), std::runtime_error);

        try {
            crane.toTrailer();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already near the trailer");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadContainer_checkIfContainerIsLoaded) {
        Crane crane;
        crane.toTrailer();
        Container container(1);
        crane.load(container);
        BOOST_CHECK_EQUAL(crane.isLoaded(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadContainerCraneIsNotOverTrailer_shouldThrowException) {
        Crane crane;
        Container container(1);

        BOOST_CHECK_THROW(crane.load(container), std::runtime_error);

        try {
            crane.load(container);
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is not over the trailer");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_loadContainerCraneIsAlreadyLoaded_shouldThrowException) {
        Crane crane;
        crane.toTrailer();
        Container container(1);
        crane.load(container);

        BOOST_CHECK_THROW(crane.load(container), std::runtime_error);

        try {
            crane.load(container);
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already loaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_unloadContainer_checkIfContainerIsUnloaded) {
        Crane crane;
        crane.toTrailer();
        Container container(1);
        crane.load(container);
        crane.unload();
        BOOST_CHECK_EQUAL(crane.isUnloaded(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_unloadContainerCraneIsNotOverTrailer_shouldThrowException) {
        Crane crane;
        Container container(1);

        BOOST_CHECK_THROW(crane.unload(), std::runtime_error);

        try {
            crane.unload();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is not over the trailer");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_unloadContainerCraneIsAlreadyUnloaded_shouldThrowException) {
        Crane crane;
        crane.toTrailer();

        BOOST_CHECK_THROW(crane.unload(), std::runtime_error);

        try {
            crane.unload();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already unloaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_pickUpContainer_checkIfContainerIsWaitingFull) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        crane.forward(1);
        crane.pickUp();
        BOOST_CHECK_EQUAL(crane.isWaitingFull(), true);
        BOOST_CHECK_EQUAL(crane.getContainer().getNumber(), 1);
    }

    BOOST_AUTO_TEST_CASE(testCrane_pickUpContainerCraneIsNotOverStack_shouldThrowException) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        BOOST_CHECK_THROW(crane.pickUp(), std::runtime_error);

        try {
            crane.pickUp();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is not over the stack");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_pickUpContainerCraneIsAlreadyLoaded_shouldThrowException) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        crane.forward(1);
        crane.pickUp();

        BOOST_CHECK_THROW(crane.pickUp(), std::runtime_error);

        try {
            crane.pickUp();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already loaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_putDownContainer_checkIfContainerIsWaitingEmpty) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        crane.forward(1);
        crane.pickUp();
        crane.putDown();
        BOOST_CHECK_EQUAL(crane.isWaitingEmpty(), true);
        BOOST_CHECK_EQUAL(crane.getContainer().getNumber(), 0);
    }

    BOOST_AUTO_TEST_CASE(testCrane_putDownContainerCraneIsNotOverStack_shouldThrowException) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        BOOST_CHECK_THROW(crane.putDown(), std::runtime_error);

        try {
            crane.putDown();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is not over the stack");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_putDownContainerCraneIsAlreadyUnloaded_shouldThrowException) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        crane.forward(1);
        crane.pickUp();
        crane.putDown();

        BOOST_CHECK_THROW(crane.putDown(), std::runtime_error);

        try {
            crane.putDown();
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Crane is already unloaded");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_stackAt_checkIfStackIsReturned) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        BOOST_CHECK_EQUAL(crane.stackAt(0).at(0).getNumber(), 1);
    }

    BOOST_AUTO_TEST_CASE(testCrane_stackAtCraneIsNotOverStack_shouldThrowException) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        BOOST_CHECK_THROW(crane.stackAt(7), std::runtime_error);

        try {
            crane.stackAt(0);
        } catch (std::runtime_error& e) {
            BOOST_CHECK_EQUAL(e.what(), "Position is out of range");
        }
    }

    BOOST_AUTO_TEST_CASE(testCrane_canPutDownContainer_checkIfContainerCanBePutDown) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        crane.forward(1);
        crane.pickUp();
        BOOST_CHECK_EQUAL(crane.canPutDown(), true);
    }

    BOOST_AUTO_TEST_CASE(testCrane_canPutDownContainerCraneIsNotOverStack_shouldThrowException) {
        Crane crane;
        ContainerStack stack;
        Container container1(1);
        stack.give(container1);
        crane.addStack(stack);

        BOOST_CHECK_EQUAL(crane.canPutDown(), false);
    }

BOOST_AUTO_TEST_SUITE_END()