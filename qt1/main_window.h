#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <vector>
#include <QKeyEvent>
#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStackedWidget>
#include <QTimer>
#include <QWidget>
#include "card.h"
#include "lhs_widget.h"
#include "randomizer.h"

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 public slots:
  void ResetCards(int amount);
  void TryUpdateAmountOfCards();
  void CardClicked(QListWidgetItem*);
  void ProcessDialogAnswer(QAbstractButton*);
  void TryChangeName();
  void TryChangeStatusOfOpened(int);
  void PickRandom();
  void CardDoubleClicked(QListWidgetItem*);
  void TryShowQuestion(int);
  void ChangeStatus(int i, Status new_status);
  void SetColorForNewActive(int i);
  void DisableHighlighting(int);
  void ShowPreviousCard();

 private:
  void ResetRandomizerWithNewAmount(int n);
  void FillVectorOfCardsWithNewAmount(int n);

  QWidget central_widget_{this};
  QHBoxLayout layout_{&central_widget_};
  LhsWidget lhs_widget_{&central_widget_};
  QListWidget rhs_widget_{&central_widget_};

  QMessageBox message_{};

  const int default_amount_of_cards = 10;
  int current_amount_of_cards = default_amount_of_cards;

  Randomizer randomizer{};
  std::vector<Card> cards{};

  int cur_question = -1;
  int previous_question = -1;
  const std::vector<std::pair<QColor, QColor>> status_to_color_{
      {QColor(220, 220, 220), QColor(200, 200, 210)},
      {QColor(220, 220, 0), QColor(190, 190, 30)},
      {QColor(0, 200, 10), QColor(0, 180, 40)}};

  std::vector<int> amount_of_gray_yellow_green{default_amount_of_cards, 0, 0};
};

#endif //MAIN_WINDOW_H
