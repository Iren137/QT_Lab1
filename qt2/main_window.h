#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QAction>
#include <QButtonGroup>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include "equation.h"

class MainWindow : public QMainWindow {
 Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 protected:

 public slots:
  void GenerateNewEquation();
  void ChangeDifficulty(int val);
  void SubmitPressed();
  void OpenLanguageSetter();
  void ChangeLanguage(const QString&);

 private:
  void ShowEquationInLabel();
  void PutAnswerVariantsOnWidget(int x1, int x2,
                                 int fake1_x1, int fake1_x2,
                                 int fake2_x1, int fake2_x2);

  QWidget* central_widget{new QWidget(this)};
  QGridLayout* layout{new QGridLayout(central_widget)};

  QLabel* equation{new QLabel(central_widget)};
  QLabel* difficulty_label{new QLabel(central_widget)};
  QPushButton* generate_button{
      new QPushButton("Generate new equation", central_widget)};
  QPushButton* submit_button{new QPushButton("Submit", central_widget)};
  QSlider* difficulty_slider{new QSlider(Qt::Horizontal, central_widget)};

  QRadioButton* variant1_{new QRadioButton{central_widget}};
  QRadioButton* variant2_{new QRadioButton{central_widget}};
  QRadioButton* variant3_{new QRadioButton{central_widget}};
  QButtonGroup* button_group_{new QButtonGroup(central_widget)};

  Equation current_equation{};

  QMessageBox message{};

  QDialog language_setter{this};
  QVBoxLayout lang_setter_layout{&language_setter};
  QComboBox combo_box{};
  QAction* action{new QAction("Change Language", this)};

  int difficulty = 1;
  int correct_variant = -1;

  bool is_language_english = true;
};

#endif //MAIN_WINDOW_H

