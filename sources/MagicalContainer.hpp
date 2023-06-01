#pragma once
#include <stdio.h>
#include <vector>


using namespace std;

namespace ariel{

    class MagicalContainer{

        vector<int> elements;

        private:
            void add(int* element);
            void remove(int* element);
            int size();

    };
}

