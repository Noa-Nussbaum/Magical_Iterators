#pragma once
#include <stdio.h>
#include <vector>


using namespace std;

namespace ariel{

    class MagicalContainer{

        vector<int> container;
        vector<int*> primePointers;

        public:
            // Default constructor
            MagicalContainer();
            // Copy constructor
            MagicalContainer(MagicalContainer& other);

            // Declare move constructor as deleted
            MagicalContainer(MagicalContainer&&) = delete;

            // Declare move assignment operator as deleted
            MagicalContainer& operator=(MagicalContainer&&) = delete;

            // Delete copy assignment operator
            MagicalContainer& operator=(const MagicalContainer&) = delete;

            // Destructor
            ~MagicalContainer();

            void deleteElementByValue(std::vector<int*>& vec, int value);
            void deleteElementByValue(std::vector<int>& vec, int value);


            bool isPrime(int number);
            void addElement(int element);
            void removeElement(int element);
            int size() const;
            // int getElement(int index);

            class AscendingIterator;
            class SideCrossIterator;
            class PrimeIterator;
  
    };

    class MagicalContainer::AscendingIterator{

        private:
            const MagicalContainer& container;
            int index;
        
        public:
            // Constructors
            AscendingIterator(const MagicalContainer& container);
            AscendingIterator(const AscendingIterator& other);
            
            // Declare move constructor as deleted
            AscendingIterator(AscendingIterator&&) = delete;

            // Declare move assignment operator as deleted
            AscendingIterator& operator=(AscendingIterator&&) = delete;
            
            // Destructor
            ~AscendingIterator();

            // Operators
            AscendingIterator& operator=(const AscendingIterator& other);
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*();
            AscendingIterator& operator++();
            AscendingIterator begin();
            AscendingIterator end();

    };

    class MagicalContainer::SideCrossIterator{

        private:
            const MagicalContainer& container;
            int rightIndex;
            int leftIndex;
            bool left;

        
        public:
            // Constructors
            SideCrossIterator(const MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);
            SideCrossIterator(const MagicalContainer& container,int leftIndex, int rightIndex);
            // Declare move constructor as deleted
            SideCrossIterator(SideCrossIterator&&) = delete;

            // Declare move assignment operator as deleted
            SideCrossIterator& operator=(SideCrossIterator&&) = delete;

            // Destructor
            ~SideCrossIterator();

            // Operators
            SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*();
            SideCrossIterator& operator++();
            SideCrossIterator begin();
            SideCrossIterator end();

    };

    class MagicalContainer::PrimeIterator{

        private:
            const MagicalContainer& container;
            int index;
        
        public:
            // Constructors
            PrimeIterator(const MagicalContainer& container);
            PrimeIterator(const PrimeIterator& other);

            // Declare move constructor as deleted
            PrimeIterator(PrimeIterator&&) = delete;

            // Declare move assignment operator as deleted
            PrimeIterator& operator=(PrimeIterator&&) = delete;

            // Destructor
            ~PrimeIterator();

            // Operators
            PrimeIterator& operator=(const PrimeIterator& other);
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*();
            PrimeIterator& operator++();
            PrimeIterator begin();
            PrimeIterator end();

    };

    
}

