#include <QPushButton>
#include "main_window.h"
#include <string>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  setMinimumSize(1000, 600);

  setCentralWidget(&central_widget_);
  layout_.addWidget(&lhs_widget_);
  layout_.addWidget(&rhs_widget_);

  connect(&rhs_widget_, SIGNAL(itemClicked(QListWidgetItem * )),
          this, SLOT(CardClicked(QListWidgetItem * )));
  connect(&rhs_widget_, SIGNAL(itemDoubleClicked(QListWidgetItem * )),
          this, SLOT(CardDoubleClicked(QListWidgetItem * )));
  connect(&message_, SIGNAL(buttonClicked(QAbstractButton * )),
          this, SLOT(ProcessDialogAnswer(QAbstractButton * )));
  connect(&rhs_widget_, SIGNAL(currentRowChanged(int)),
          this, SLOT(DisableHighlighting(int)));

  message_.addButton(QString("Yes"), QMessageBox::YesRole);
  message_.addButton(QString("No"), QMessageBox::NoRole);
  message_.setText(
      "Are you sure to change amount of cards?\nAll changes will be lost.\n");
  message_.setWindowTitle("Are you sure?");

  ResetCards(default_amount_of_cards);

  rhs_widget_.setSpacing(4);
  rhs_widget_.setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
}

void MainWindow::DisableHighlighting(int x) {
  rhs_widget_.setCurrentRow(-1);
}

MainWindow::~MainWindow() = default;

void MainWindow::TryUpdateAmountOfCards() {
  message_.open();
}

void MainWindow::CardClicked(QListWidgetItem* item) {
  int i = rhs_widget_.row(item);
  TryShowQuestion(i);
}

void MainWindow::ResetCards(int amount) {
  for (int i = 0; i < current_amount_of_cards; i++) {
    delete rhs_widget_.takeItem(0);
  }
  cur_question = -1;
  previous_question = -1;

  amount_of_gray_yellow_green[0] = amount;
  amount_of_gray_yellow_green[1] = 0;
  amount_of_gray_yellow_green[2] = 0;

  lhs_widget_.green_progress->setValue(0);
  lhs_widget_.total_progress->setValue(0);
  lhs_widget_.title.setText("");
  lhs_widget_.number.setText("");

  current_amount_of_cards = amount;
  ResetRandomizerWithNewAmount(current_amount_of_cards);
  FillVectorOfCardsWithNewAmount(current_amount_of_cards);

  for (int i = 0; i < amount; i++) {
    rhs_widget_.addItem(QString::fromStdString(cards[i].name));
    rhs_widget_.item(i)->setSizeHint(QSize(1000, 50));
    QBrush brush(QColor(220, 220, 220));
    rhs_widget_.item(i)->setBackground(brush);
  }
}

void MainWindow::ProcessDialogAnswer(QAbstractButton* button) {
  if (button->text() == QString("Yes")) {
    ResetCards(lhs_widget_.GetNewAmountOfCards());
  }
}

void MainWindow::ResetRandomizerWithNewAmount(int n) {
  randomizer = Randomizer();
  for (int i = 0; i < n; i++) {
    randomizer.Add(i);
  }
}

void MainWindow::FillVectorOfCardsWithNewAmount(int n) {
  cards.clear();
  cards.resize(n);
  for (int i = 0; i < n; i++) {
    cards[i].status = gray;
    cards[i].name = "Card " + std::to_string(i + 1);
  }
}

void MainWindow::TryChangeName() {
  if (cur_question == -1) {
    return;
  }
  QString str = lhs_widget_.edit_title->text();
  cards[cur_question].name = str.toStdString();
  rhs_widget_.item(cur_question)->setText(str);
  lhs_widget_.title.setText(str);
}

void MainWindow::TryChangeStatusOfOpened(int new_status) {
  if (cur_question == -1) {
    return;
  }
  if (cards[cur_question].status == new_status) {
    return;
  }
  ChangeStatus(cur_question, static_cast<Status>(new_status));
}

void MainWindow::PickRandom() {
  int i = randomizer.Generate();
  if (i == -1) {
    return;
  }
  TryShowQuestion(i);
}

void MainWindow::TryShowQuestion(int i) {
  if (i == cur_question) {
    return;
  }
  SetColorForNewActive(i);
  previous_question = cur_question;
  cur_question = i;
  lhs_widget_.edit_title->clear();
  lhs_widget_.chose_status->setCurrentIndex(cards[i].status);
  lhs_widget_.title.setText(QString::fromStdString(cards[i].name));
  lhs_widget_.number.setText(QString::number(i + 1) + ".");
}

void MainWindow::CardDoubleClicked(QListWidgetItem* item) {
  int i = rhs_widget_.row(item);
  if (cards[i].status == gray || cards[i].status == yellow) {
    ChangeStatus(i, green);
  } else {
    ChangeStatus(i, yellow);
  }
}

void MainWindow::ChangeStatus(int i, Status new_status) {
  Status old_status = cards[i].status;
  amount_of_gray_yellow_green[old_status]--;
  amount_of_gray_yellow_green[new_status]++;
  lhs_widget_.chose_status->setCurrentIndex(new_status);
  lhs_widget_.total_progress->setValue(100 * (amount_of_gray_yellow_green[1] +
      amount_of_gray_yellow_green[2]) / cards.size());
  lhs_widget_.green_progress->setValue(
      100 * amount_of_gray_yellow_green[2] / cards.size());
  cards[i].status = static_cast<Status>(new_status);
  SetColorForNewActive(i);
  if (new_status == green) {
    randomizer.Delete(i);
  } else {
    randomizer.Add(i);
  }
}

void MainWindow::SetColorForNewActive(int i) {
  if (cur_question != -1) {
    QBrush brush(status_to_color_[cards[cur_question].status].first);
    rhs_widget_.item(cur_question)->setBackground(brush);
  }
  QBrush brush(status_to_color_[cards[i].status].second);
  rhs_widget_.item(i)->setBackground(brush);
}

void MainWindow::ShowPreviousCard() {
  if (previous_question == -1) {
    return;
  }
  TryShowQuestion(previous_question);
}
