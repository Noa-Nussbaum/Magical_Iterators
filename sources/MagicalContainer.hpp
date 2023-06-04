#pragma once
#include <stdio.h>
#include <vector>


using namespace std;

namespace ariel{

    class MagicalContainer{

        vector<int> container;

        public:
            // Default constructor
            MagicalContainer();
            // Copy constructor
            MagicalContainer(MagicalContainer& other);

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
        
        public:
            // Constructors
            PrimeIterator(const MagicalContainer& container);
            PrimeIterator(const PrimeIterator& other);
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

