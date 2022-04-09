#ifndef LHS_WIDGET_H
#define LHS_WIDGET_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

class MainWindow;

class LhsWidget : public QWidget {
 public:
  explicit LhsWidget(QWidget* parent = nullptr);
  ~LhsWidget() override;
  int GetNewAmountOfCards();

 private:
  void SetStyle();

  QLabel title{"", this};
  QLabel number{"", this};
  QLabel status{"Choose status", this};

  QPushButton* update_button_{new QPushButton("Update", this)};
  QPushButton* previous_card_button{new QPushButton("Previous card", this)};
  QPushButton* pick_random_button_{new QPushButton("Pick one randomly", this)};
  QSpinBox* count_of_cards{new QSpinBox{this}};
  QLineEdit* edit_title{new QLineEdit(this)};
  QComboBox* chose_status{new QComboBox(this)};
  QProgressBar* total_progress{new QProgressBar(this)};
  QProgressBar* green_progress{new QProgressBar(this)};

  QGridLayout* layout_{new QGridLayout(this)};

  friend class MainWindow;
};

#endif //LHS_WIDGET_H
