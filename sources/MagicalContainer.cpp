#include "MagicalContainer.hpp"


using namespace std;

namespace ariel{


    // Default constructor
    MagicalContainer::MagicalContainer(){}
    // Copy constructor
    MagicalContainer::MagicalContainer(MagicalContainer& other){}

    void MagicalContainer::addElement(int element){}
    void MagicalContainer::removeElement(int element){}
    int MagicalContainer::size() const{}

    class AscendingIterator;
    class SideCrossIterator;
    class PrimeIterator;


    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container):container(container){}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other):container(other){}
    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){}
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{}
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{}
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{}
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{}
    int MagicalContainer::AscendingIterator::operator*(){}
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){}
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){}
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){}



    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other){}
    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){}
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{}
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{}
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{}
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{}
    int MagicalContainer::SideCrossIterator::operator*(){}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){}


    // Constructors
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container){}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other){}
    // Destructor
        MagicalContainer::PrimeIterator::~PrimeIterator(){}

    // Operators
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){}
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{}
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{}
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{}
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{}
    int MagicalContainer::PrimeIterator::operator*(){}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){}




}
