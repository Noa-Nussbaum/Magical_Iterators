#include "MagicalContainer.hpp"


using namespace std;

namespace ariel{


    // Default constructor
    MagicalContainer::MagicalContainer(){}
    // Copy constructor
    MagicalContainer::MagicalContainer(MagicalContainer& other){}

    void MagicalContainer::addElement(int element){}
    void MagicalContainer::removeElement(int element){}
    int MagicalContainer::size() const{
        return 0;
    }

    class AscendingIterator;
    class SideCrossIterator;
    class PrimeIterator;


    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container):container(container){}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other):container(other.container){}
    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        return false;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return false;
    }
    int MagicalContainer::AscendingIterator::operator*(){
        return 0;
    }
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        return *this;
    }



    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container):container(container){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other):container(other.container){}
    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return false;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return false;
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return false;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return false;
    }
    int MagicalContainer::SideCrossIterator::operator*(){
        return 0;
    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        return *this;
    }


    // Constructors
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container):container(container){}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other):container(other.container){}
    // Destructor
        MagicalContainer::PrimeIterator::~PrimeIterator(){}

    // Operators
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        return false;
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return false;
    }
    int MagicalContainer::PrimeIterator::operator*(){
        return 0;
    }
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        return *this;
    }

}
