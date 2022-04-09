#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <unordered_map>
#include <vector>

class Randomizer {
 public:
  Randomizer();
  int Generate();
  void Delete(int x);
  void Add(int x);

 private:
  int last_generated = -1;
  std::vector<int> vec_{};
  std::unordered_map<int, int> index_of_{};
};

#endif //RANDOMIZER_H
