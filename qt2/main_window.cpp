#include <random>
#include <QMenu>
#include <QMenuBar>
#include <iostream>
#include "main_window.h"

MainWindow::~MainWindow() = default;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  setMinimumSize(500, 300);
  resize(500, 300);

  setCentralWidget(central_widget);

  layout->addWidget(equation, 3, 0, 1, 3, Qt::AlignAbsolute);
  layout->addWidget(difficulty_label, 1, 0, 1, 3, Qt::AlignBottom);
  layout->addWidget(generate_button, 0, 0, 1, 3);
  layout->addWidget(submit_button, 7, 0, 1, 3);
  layout->addWidget(difficulty_slider, 2, 0, 1, 3);
  layout->addWidget(variant1_, 4, 0, 1, 3, Qt::AlignCenter);
  layout->addWidget(variant2_, 5, 0, 1, 3, Qt::AlignCenter);
  layout->addWidget(variant3_, 6, 0, 1, 3, Qt::AlignCenter);

  difficulty_slider->setMinimum(10);
  difficulty_slider->setMaximum(100);
  difficulty_slider->setValue(10);

  button_group_->addButton(variant1_, 1);
  button_group_->addButton(variant2_, 2);
  button_group_->addButton(variant3_, 3);

  message.setWindowTitle("Result");
  difficulty_label->setText("Difficulty");

  QMenu* menu = menuBar()->addMenu("Menu");
  menu->addAction(action);
  lang_setter_layout.addWidget(&combo_box);
  combo_box.addItem(QString("English"));
  combo_box.addItem(QString("Русский"));
  language_setter.setWindowTitle("Choose language");
  language_setter.setMinimumSize(200, 100);

  connect(&combo_box, SIGNAL(currentTextChanged(const QString &)),
          this, SLOT(ChangeLanguage(const QString&)));
  connect(action, SIGNAL(triggered()), this, SLOT(OpenLanguageSetter()));
  connect(generate_button, SIGNAL(clicked()),
          this, SLOT(GenerateNewEquation()));
  connect(difficulty_slider, SIGNAL(valueChanged(int)),
          this, SLOT(ChangeDifficulty(int)));
  connect(submit_button, SIGNAL(clicked()),
          this, SLOT(SubmitPressed()));
  connect(&message, SIGNAL(finished(int)),
          this, SLOT(GenerateNewEquation()));

  equation->setFont(QFont("Times New Roman", 20));
  variant1_->setFont(QFont("Times New Roman", 15));
  variant2_->setFont(QFont("Times New Roman", 15));
  variant3_->setFont(QFont("Times New Roman", 15));

  generate_button->setStyleSheet("QPushButton {background-color: yellow}");
  submit_button->setStyleSheet("QPushButton {background-color: green}");
  setObjectName("WholeWindow");
  setStyleSheet(
      "#WholeWindow { background-color : rgba(220, 230, 255, 230) } ");

  GenerateNewEquation();
}

void MainWindow::GenerateNewEquation() {
  static std::mt19937 gen((std::random_device()()));
  std::uniform_int_distribution<int> root_dist(-5 * difficulty, 5 * difficulty);
  std::uniform_int_distribution<int>
      a_dist(3 * (difficulty - 1), 7 * (difficulty - 1));
  std::uniform_int_distribution<int> coin_dist(0, 1);
  int x1 = root_dist(gen);
  int x2 = root_dist(gen);

  PutAnswerVariantsOnWidget(x1, x2, root_dist(gen), root_dist(gen),
                            root_dist(gen), root_dist(gen));

  int a = a_dist(gen);
  if (coin_dist(gen) == 1) {
    a = -a;
  }
  if (a == 0) {
    a = 1;
  }
  current_equation.a = a;
  current_equation.b = -(x1 + x2) * a;
  current_equation.c = x1 * x2;
  current_equation.x1 = std::min(x1, x2);
  current_equation.x2 = std::max(x1, x2);

  ShowEquationInLabel();
}

void MainWindow::ShowEquationInLabel() {
  QString str{};
  if (current_equation.a == 1) {
    str += "x^2";
  } else if (current_equation.a == -1) {
    str += "-x^2";
  } else {
    str += QString::number(current_equation.a) + " * x^2";
  }
  if (current_equation.b != 0) {
    if (current_equation.b == 1) {
      str += " + x";
    } else if (current_equation.b == -1) {
      str += " - x";
    } else if (current_equation.b < 0) {
      str += " - " + QString::number(-current_equation.b) + " * x";
    } else {
      str += " + " + QString::number(current_equation.b) + " * x";
    }
  }
  if (current_equation.c != 0) {
    if (current_equation.c == 1) {
      str += " + 1";
    } else if (current_equation.c == -1) {
      str += " - 1";
    } else if (current_equation.c < 0) {
      str += " - " + QString::number(-current_equation.c);
    } else {
      str += " + " + QString::number(current_equation.c);
    }
  }
  str += " = 0";
  equation->setText(str);
}

void MainWindow::ChangeDifficulty(int val) {
  difficulty = val / 10;
}

void MainWindow::SubmitPressed() {
  if (button_group_->checkedId() == -1) {
    return;
  }
  if (button_group_->checkedId() == correct_variant) {
    if (is_language_english) {
      message.setText("Correct!");
    } else {
      message.setText("Правильно!");
    }
  } else {
    if (is_language_english) {
      message.setText("Incorrect!\nThe correct answer was "
                          + button_group_->button(correct_variant)->text());
    } else {
      message.setText("Неправильно!\nПравильный ответ был "
                          + button_group_->button(correct_variant)->text());
    }
  }
  message.open();
}

void MainWindow::PutAnswerVariantsOnWidget(int x1, int x2,
                                           int fake1_x1, int fake1_x2,
                                           int fake2_x1, int fake2_x2) {
  if (x1 > x2) {
    std::swap(x1, x2);
  }
  if (fake1_x1 > fake1_x2) {
    std::swap(fake1_x1, fake1_x1);
  }
  if (fake2_x1 > fake2_x2) {
    std::swap(fake2_x1, fake2_x2);
  }
  if (x1 == fake1_x1 && x2 == fake2_x2) {
    fake1_x1++;
  }
  if (x1 == fake2_x1 && x2 == fake2_x2) {
    fake2_x1--;
  }
  if (fake1_x1 == fake2_x1 && fake1_x2 == fake2_x2) {
    fake1_x2++;
  }
  static std::mt19937 gen((std::random_device()()));
  static std::uniform_int_distribution<int> dist(1, 3);
  correct_variant = dist(gen);
  std::vector<std::pair<int, int>> vec{
      {fake1_x1, fake1_x2}, {fake2_x1, fake2_x2}};
  for (int i = 1; i <= 3; i++) {
    if (i == correct_variant) {
      button_group_->button(i)->setText(QString::number(x1) + "; "
                                            + QString::number(x2));
      continue;
    }
    button_group_->button(i)->setText(QString::number(vec.back().first) + "; "
                                          + QString::number(vec.back().second));
    vec.pop_back();
  }
}

void MainWindow::OpenLanguageSetter() {
  language_setter.open();
}

void MainWindow::ChangeLanguage(const QString& str) {
  if (str == "English") {
    is_language_english = true;
    message.setWindowTitle("Result");
    language_setter.setWindowTitle("Choose language");
    action->setText("Change language");
    generate_button->setText("Generate new equation");
    submit_button->setText("Submit");
    difficulty_label->setText("Difficulty");
  } else {
    is_language_english = false;
    message.setWindowTitle("Результат");
    language_setter.setWindowTitle("Выберите язык");
    action->setText("Изменить язык");
    generate_button->setText("Сгенерировать новое уравнение");
    submit_button->setText("Отправить");
    difficulty_label->setText("Сложность");
  }
}

