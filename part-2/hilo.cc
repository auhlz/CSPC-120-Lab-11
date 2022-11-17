// Alex Labitigan
// CPSC 120-12
// 2022-10-31
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab qq-01
// Partners: @dianasuceli
//
// States
//

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) : secret_(secret), guesses_left_(4) {}

int GameState::Secret() const { return secret_; }
int GameState::GuessesLeft() const { return guesses_left_; }
bool GameState::GuessCorrect(int guess) const {
  return (guess == GameState::Secret());
}
bool GameState::GuessTooBig(int guess) const {
  return (guess > GameState::Secret());
}

bool GameState::GuessTooSmall(int guess) const {
  return (guess < GameState::Secret());
}

void GameState::CountGuess() { guesses_left_ -= 1; }

bool GameState::GameOver() const { return (GameState::GuessesLeft() == 0); }

int RandomSecretNumber() {
  std::random_device random;
  std::mt19937 generator(random());
  std::uniform_int_distribution<int> distribution(1, 10);
  int number = distribution(generator);
  return number;
}
