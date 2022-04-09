#include <QApplication>
#include "main_window.h"

using namespace std;

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow window;
  window.setWindowTitle("Random for Mathematical Analysis");
  window.show();
  return QApplication::exec();
}
