#include "doctest.h"
#include "sources/MagicalContainer.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;

namespace ariel{
    
    TEST_CASE("Initiation errors"){
        MagicalContainer container;
        // Regular check
        CHECK_NOTHROW(container.addElement(1));
        // Negative number
        CHECK_NOTHROW(container.addElement(-78));
        // Double
        // CHECK_THROWS(container.addElement(25.5));
        // Large number
        CHECK_NOTHROW(container.addElement(148978));

    }
    TEST_CASE("Initiation of container"){
        MagicalContainer container;

        CHECK(container.size()==0);

        container.addElement(88);
        container.addElement(72);
        container.addElement(25);
        container.addElement(93);
        container.addElement(4);

        CHECK(container.size()==5);

        container.removeElement(88);

        CHECK(container.size()==4);

        // The number 3 element isn't in the container. Should throw
        CHECK_THROWS(container.removeElement(3));
        
    }
    TEST_CASE("AscendingIterator tests"){
        MagicalContainer magic;
        
        MagicalContainer::AscendingIterator ascending(magic);

        CHECK(ascending == ascending.begin());
        CHECK(ascending == ascending.end());

        magic.addElement(8);
        magic.addElement(72);
        magic.addElement(25);
        magic.addElement(93);
        magic.addElement(4);

        // Check order is ascending
        CHECK(*ascending == 4);
        ++ascending;
        CHECK(*ascending == 8);
        ++ascending;
        CHECK(*ascending == 25);
        ++ascending;
        CHECK(*ascending == 72);
        ++ascending;
        CHECK(*ascending == 93);
        ++ascending;

    }

    TEST_CASE("SideCrossIterator tests"){
        MagicalContainer magic;
        
        MagicalContainer::SideCrossIterator SideCross(magic);

        CHECK(magic.size()==0);

        magic.addElement(8);
        magic.addElement(72);
        magic.addElement(25);

        CHECK(magic.size()==3);

        // Check order is ascending
        CHECK(*SideCross == 8);
        ++SideCross;
        CHECK(*SideCross == 25);
        ++SideCross;
        CHECK(*SideCross == 72);
        ++SideCross;

        magic.removeElement(72);
        CHECK(magic.size()==2);

    }

    TEST_CASE("PrimeIterator tests"){
        MagicalContainer magic;
        
        MagicalContainer::PrimeIterator Prime(magic);

        CHECK(magic.size()==0);

        magic.addElement(8);
        magic.addElement(72);
        magic.addElement(25);
        magic.addElement(17);
        magic.addElement(7);
        magic.addElement(87);
        magic.addElement(5);
        magic.addElement(11);


        CHECK(magic.size()==4);

        // Check order is ascending
        CHECK(*Prime == 17);
        ++Prime;
        CHECK(*Prime == 7);
        ++Prime;
        CHECK(*Prime == 5);
        ++Prime;
        CHECK(*Prime == 11);
        ++Prime;

        magic.removeElement(5);
        
        CHECK(magic.size()==3);

    }


}