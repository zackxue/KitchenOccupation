#ifndef DEBUG_H
#define DEBUG_H

#include "../DenseKitchen.hpp"

class DenseKitchen;

//TODO this class is supposed to be friends with everyone...

namespace debug{
    class Debug{
    public:
        Debug();
        ~Debug();
        void start(DenseKitchen *state);
    };
}

#endif