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
        return other.index < index;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return other.index > index;    
        }
    int MagicalContainer::AscendingIterator::operator*(){
        if (index >= container.container.size()) {
            throw runtime_error("Iterator out of range");
        }

        // Create a copy of the container's elements
        vector<int> sortedElements = container.container;

        // Sort the elements in ascending order
        sort(sortedElements.begin(), sortedElements.end());

        // Return the element at the current index
        return sortedElements[static_cast<std::vector<int>::size_type>(index)];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        if (index+1 > container.container.size()) {
            throw runtime_error("Iterator out of range");
        }
        index++;
        return *this;
    }


    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        AscendingIterator *answer = new AscendingIterator(container);
        answer->index=0;
        return *answer;

    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        AscendingIterator *answer = new AscendingIterator(container);
        answer->index=container.size();
        return *answer;
    }


    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container):container(container), leftIndex(0), rightIndex(container.size()), left(false){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other):container(other.container), leftIndex(0), rightIndex(container.size()), left(false){}
    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        // if(!(&other==this)){
        //     if(&container != &(other.container)){
        //         throw runtime_error("Different containers");
        //     }
        //     index = other.index;
        // }
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return other.rightIndex == rightIndex && other.leftIndex == leftIndex;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return other.rightIndex != rightIndex && other.leftIndex != leftIndex;;
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return leftIndex>other.leftIndex && rightIndex>other.rightIndex;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return leftIndex<other.leftIndex && rightIndex<other.rightIndex;
    }
    int MagicalContainer::SideCrossIterator::operator*(){
        if (leftIndex >= container.container.size()/2 || rightIndex <= container.container.size()/2) {
            throw runtime_error("Iterator out of range");
        }
        // Create a copy of the container's elements
        vector<int> sortedElements = container.container;

        // Sort the elements in ascending order
        sort(sortedElements.begin(), sortedElements.end());

        if(left){
            return sortedElements[static_cast<std::vector<int>::size_type>(leftIndex)];
        }
        // Return the element at the current index
        return sortedElements[static_cast<std::vector<int>::size_type>(rightIndex)];
    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        SideCrossIterator *answer = new SideCrossIterator(container);
        answer->leftIndex=0;
        answer->rightIndex=answer->container.size();
        return *answer;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        // Finish this
        SideCrossIterator *answer = new SideCrossIterator(container);
        // if(container.size)
        answer->rightIndex=answer->container.size()/2;
        return *answer;
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
