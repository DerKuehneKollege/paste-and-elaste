#include <QApplication>
#include <QGuiApplication>
#include <QDebug>

#include "src/ui/main-window/MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon("PasteAndElaste.ico"));

    auto clipboard = QGuiApplication::clipboard();

    auto window = new MainWindow(nullptr, clipboard);
    window->show();

    return QApplication::exec();
}