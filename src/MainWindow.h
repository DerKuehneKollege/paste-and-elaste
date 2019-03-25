#ifndef PASTEANDELASTE_MAINWINDOW_H
#define PASTEANDELASTE_MAINWINDOW_H

#include <QDebug>
#include <QClipboard>
#include <QMainWindow>
#include <QtCore/QStringListModel>

#include "UiMainWindow.h"

class MainWindow : public QMainWindow {
Q_OBJECT

private:
    Ui::MainWindow ui{};
    QClipboard* clipboard{QGuiApplication::clipboard()};
    QStringListModel* model{};
    QStringList stringList{};

public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        ui.setupUi(this);

        model = new QStringListModel();

        model->setStringList(stringList);
        ui.tableView->setModel(model);

        QObject::connect(
                ui.searchButton,
                SIGNAL(clicked()),
                this,
                SLOT(onSearchButtonClick())
        );

        QObject::connect(
                clipboard,
                SIGNAL(dataChanged()),
                this,
                SLOT(onClipboardDataChanged())
        );
    }

private slots:
    void onSearchButtonClick() {
        qDebug() << "Search button clicked!";
    };

    void onClipboardDataChanged() {
        qDebug() << "Clipboard-Data changed!";
        qDebug() << "Clipboard-Text: [" << clipboard->text() << "]";
        stringList.append(clipboard->text());
        model->setStringList(stringList);
    };
};


#endif //PASTEANDELASTE_MAINWINDOW_H
