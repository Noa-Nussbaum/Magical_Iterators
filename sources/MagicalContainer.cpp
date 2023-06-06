#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
#include <math.h>


using namespace std;

namespace ariel{


    // Default constructor
    MagicalContainer::MagicalContainer(){}

    // Copy constructor
    MagicalContainer::MagicalContainer(MagicalContainer& other){
        container=other.container;
        primes=other.primes;
    }
    MagicalContainer::~MagicalContainer(){}

    void MagicalContainer::addElement(int element){
        container.push_back(element);
        // If it's prime, add it to the primes list
        if(isPrime(element)){
            primes.push_back(element);
        }
    }
    // Check if number is prime
    bool MagicalContainer::isPrime(int element){
        if (element < 2){
            return false;
        }
        // Iterate until sqrt(n)
        for (int i = 2; i <= sqrt(element); ++i){
            if (element % i == 0)
                return false;
        }
        return true;
    }

    // Helps removing element from primes
    void MagicalContainer::deleteElementByValue(std::vector<int>& vec, int value) {
        vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
    }

    void MagicalContainer::removeElement(int element){
        bool answer = false;
        // Make sure not empty
        if(container.empty()){
            throw runtime_error("The container is empty");
        }
        // Iterate and delete when found
        for(auto i = container.begin(); i!=container.end(); i++){
            if(*i == element){
                container.erase(i);
                deleteElementByValue(primes,element);
                answer = true;
            }
        }
        // If not found
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

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){}
    
    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        // Make sure not same
        if(!(&other==this)){
            if(&container != &(other.container)){
                throw runtime_error("Different containers");
            }
            // Assign
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
            // Make sure in bounds
            throw runtime_error("Iterator out of range");
        }

        // First sort then return value
        vector<int> sorted = container.container;
        sort(sorted.begin(), sorted.end());
        return sorted[static_cast<std::vector<int>::size_type>(index)];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        // Make sure in range
        if (index+1 > container.container.size()) {
            throw runtime_error("Iterator out of range");
        }
        index++;
        return *this;
    }


    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        // Beginning is 0
        AscendingIterator *answer = new AscendingIterator(container);
        answer->index=0;
        return *answer;

    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        // End is the edge
        AscendingIterator *answer = new AscendingIterator(container);
        answer->index=container.size();
        return *answer;
    }



    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container):container(container), leftIndex(0), rightIndex(container.size()), left(true){
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other):container(other.container), leftIndex(other.leftIndex), rightIndex(other.rightIndex), left(other.left){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container,int leftIndex, int rightIndex):container(container), leftIndex(leftIndex), rightIndex(rightIndex), left(true){}
    
    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        // Make sure not equal
        if(!(&other==this)){
            if(&container!=&other.container){
                throw runtime_error("Assigning to different containers");
            }
            // Assign the same values
            leftIndex = other.leftIndex;
            rightIndex = other.rightIndex;
            left = other.left;
        }
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return other.rightIndex == rightIndex && other.leftIndex == leftIndex;
    }
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return !(other == *this);
    }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return leftIndex>other.leftIndex || rightIndex<other.rightIndex;
    }
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return leftIndex<other.leftIndex || rightIndex>other.rightIndex;
    }
    int MagicalContainer::SideCrossIterator::operator*(){
        // Make sure in range
        if (leftIndex > container.container.size()/2 || rightIndex < container.container.size()/2) {
            throw runtime_error("Iterator is out of range");
        }

        // First we sort
        vector<int> sorted = container.container;
        sort(sorted.begin(), sorted.end());

        // If the last place we changed was left
        if(left){
            return sorted[static_cast<std::vector<int>::size_type>(leftIndex)];
        }
        // Return the answer at the index
        return sorted[static_cast<std::vector<int>::size_type>(rightIndex)];
    }
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        // Make sure in bounds
        if(leftIndex < rightIndex){
            // Then increment
            if(left == true){
                    rightIndex--;
                    left = false;
                }
            else{
                leftIndex++;
                left = true;
            }
        
        }
        else{
            throw runtime_error("Incrementing beyond the end");
        }
        return *this;
    }
    
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        // Initialize new iterator because default is 0
        return SideCrossIterator(container);
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        // The end here is the middle 
        int size = container.size();
        int start = 0;
        int end = size;
        start = size/2;
        end = size/2;
        
        return SideCrossIterator(container, start, end);
    }



    // Constructors
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container):container(container), index(0){}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other):container(other.container), index(other.index){}
    
    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator(){}

    // Operators
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        // Check if same
        if(!(&other==this)){
            if(&container != &(other.container)){
                throw runtime_error("Different containers");
            }
            // Assign
            index = other.index;
        }
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return other.index == index;
    }
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return other.index != index;
    }
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        return index>other.index;
    }
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return index<other.index;
    }
    int MagicalContainer::PrimeIterator::operator*(){
        // Check if in range
        if (index >= this->container.primes.size()) {
            throw runtime_error("Iterator out of range in *");
        }
        
        // Sort before returning
        vector<int> sorted = container.primes;
        sort(sorted.begin(), sorted.end());
        return sorted[static_cast<std::vector<int>::size_type>(index)];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        // Make sure in range
        if (index+1 > this->container.primes.size()) {
            throw runtime_error("Iterator out of range");
        }
        // If in range increment
        index++;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        // Beginning here is 0
        index=0;
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        // End here is the size of the vector
        index=container.primes.size();
        return *this;
    }

}
