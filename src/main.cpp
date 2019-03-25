#include <QApplication>
#include <QDebug>

#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    auto *clipboard = new ClipboardAdapter;

    auto *window = new MainWindow;
    window->show();

    return QApplication::exec();
}