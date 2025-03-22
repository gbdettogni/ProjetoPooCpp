//
// Created by betelgeuse on 22/03/25.
//

#ifndef PAIR_H
#define PAIR_H
#include <string>

namespace cpp_utils {

class Pair {
public:
    const std::string member1;
    const std::string member2;

    Pair(const std::string member1, const std::string member2)
        : member1(member1),
          member2(member2) {
    }
};

} // cpp_utils

#endif //PAIR_H
