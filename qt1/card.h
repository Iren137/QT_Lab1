#ifndef CARD_H
#define CARD_H

#include <string>

enum Status {
  gray = 0,
  yellow = 1,
  green = 2
};

struct Card {
  std::string name{};
  Status status;
};

#endif //CARD_H
