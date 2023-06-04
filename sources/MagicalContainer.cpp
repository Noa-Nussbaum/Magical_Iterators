#include "MagicalContainer.hpp"
#include <stdexcept>


using namespace std;

namespace ariel{


    // Default constructor
    MagicalContainer::MagicalContainer(){}
    // Copy constructor
    MagicalContainer::MagicalContainer(MagicalContainer& other){
        container=other.container;
    }

    void MagicalContainer::addElement(int element){
        container.push_back(element);
    }
    void MagicalContainer::removeElement(int element){
        bool answer = false;
        if(container.empty()){
            throw runtime_error("The container is empty");
        }
        for(auto i = container.begin(); i!=container.end(); i++){
            if(*i == element){
                container.erase(i);
                answer = true;
            }
        }
        if(answer == false){
            throw runtime_error("Element not found for erasing");
        }
    }
    int MagicalContainer::size() const{
        return container.size();
    }

    class AscendingIterator;
    class SideCrossIterator;
    class PrimeIterator;


    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container):container(container), index(0){
    }
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other):container(other.container),index(other.index){}
    // MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other, int index):container(other.container),index(index){}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}
    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        if(!(&other==this)){
            if(&container != &(other.container)){
                throw runtime_error("Different containers");
            }
            index = other.index;
        }
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return other.index == index;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return other.index != index;
    }
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        return other.index > index;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return other.index < index;    
        }
    int MagicalContainer::AscendingIterator::operator*(){
        sort(this->begin(), this->end());
        return container.container[index];
        // return this->container.container[index];
    }
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        index++;
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        AscendingIterator *answer = new AscendingIterator(container);
        answer->index=0;
        return *answer;

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
