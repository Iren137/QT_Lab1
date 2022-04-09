#include "randomizer.h"
#include <random>

Randomizer::Randomizer() {}

int Randomizer::Generate() {
  static std::mt19937 gen((std::random_device()()));
  if (vec_.empty()) {
    return -1;
  }
  if (vec_.size() == 1) {
    last_generated = vec_[0];
    return vec_[0];
  }
  std::uniform_int_distribution<int> dist(0, static_cast<int>(vec_.size()) - 1);
  int i = dist(gen);
  if (vec_[i] != last_generated) {
    last_generated = vec_[i];
    return vec_[i];
  }
  if (i == 0) {
    last_generated = vec_[i + 1];
    return vec_[i + 1];
  }
  last_generated = vec_[i - 1];
  return vec_[i - 1];
}

void Randomizer::Delete(int x) {
  if (index_of_.find(x) == index_of_.end()) {
    return;
  }
  vec_[index_of_[x]] = vec_.back();
  vec_.pop_back();
  index_of_.erase(x);
}

void Randomizer::Add(int x) {
  if (index_of_.find(x) != index_of_.end()) {
    return;
  }
  vec_.push_back(x);
  index_of_[x] = static_cast<int>(vec_.size()) - 1;
}
