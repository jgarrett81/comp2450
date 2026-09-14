#include "hero/Bag.h"
#include "bestiary/Search.h"

using namespace dungeon;

int main() {
    Bag<int> testBag;

    findByName(testBag, "Bob");

    return 0;
}