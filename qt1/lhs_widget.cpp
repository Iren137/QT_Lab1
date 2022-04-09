#include "lhs_widget.h"
#include <QMainWindow>

LhsWidget::LhsWidget(QWidget* parent)
    : QWidget(parent) {
  layout_->addWidget(&number, 0, 0, 1, 1, Qt::AlignLeft);
  layout_->addWidget(&status, 0, 1, 1, 1, Qt::AlignRight);
  layout_->addWidget(chose_status, 0, 2, 1, 1, Qt::AlignLeft);
  layout_->addWidget(&title, 1, 0, 1, 3);
  layout_->addWidget(edit_title, 2, 0, 1, 3);
  layout_->addWidget(previous_card_button, 3, 0, 1, 1, Qt::AlignCenter);
  layout_->addWidget(pick_random_button_, 3, 2, 1, 1, Qt::AlignCenter);
  layout_->addWidget(total_progress, 4, 0, 1, 3);
  layout_->addWidget(green_progress, 5, 0, 1, 3);
  layout_->addWidget(update_button_, 6, 0, 1, 2);
  layout_->addWidget(count_of_cards, 6, 2, 1, 1, Qt::AlignLeft);

  total_progress->setValue(0);
  green_progress->setValue(0);

  edit_title->setPlaceholderText("Change title");

  chose_status->addItem("Unseen");
  chose_status->addItem("Repeat");
  chose_status->addItem("Done");

  SetStyle();

  connect(pick_random_button_, SIGNAL(clicked()),
          parentWidget()->parentWidget(), SLOT(PickRandom()));
  connect(chose_status, SIGNAL(activated(int)),
          parentWidget()->parentWidget(), SLOT(TryChangeStatusOfOpened(int)));
  connect(edit_title, SIGNAL(returnPressed()),
          parentWidget()->parentWidget(), SLOT(TryChangeName()));
  connect(update_button_,
          SIGNAL(clicked()),
          parentWidget()->parentWidget(),
          SLOT(TryUpdateAmountOfCards()));
  connect(previous_card_button, SIGNAL(clicked()),
          parentWidget()->parentWidget(), SLOT(ShowPreviousCard()));
}

void LhsWidget::SetStyle() {
  QFont font("Times New Roman", 20, QFont::Cursive);
  title.setFont(font);

  font = QFont("Times New Roman", 20, QFont::Cursive);
  number.setFont(font);
  setObjectName("LHS");
  setStyleSheet("#LHS { background-color : rgba(0, 0, 220, 15) } ");
  font = QFont("Times New Roman", 20, QFont::Bold);
  pick_random_button_->setFont(font);
  update_button_->setFont(font);
  previous_card_button->setFont(font);
  pick_random_button_->setStyleSheet("QPushButton {background-color: blue}");
  previous_card_button->setStyleSheet("QPushButton {background-color: purple}");
  update_button_->setStyleSheet("QPushButton {background-color: orange}");
}
int LhsWidget::GetNewAmountOfCards() {
  return count_of_cards->value();
}

LhsWidget::~LhsWidget() = default;
