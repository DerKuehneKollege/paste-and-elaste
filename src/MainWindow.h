#ifndef PASTEANDELASTE_MAINWINDOW_H
#define PASTEANDELASTE_MAINWINDOW_H

#include <QDebug>
#include <QClipboard>
#include <QMainWindow>
#include <QtCore/QStringListModel>

#include "UiMainWindow.h"
#include "ClipboardEntryModel.h"

class MainWindow : public QMainWindow {
Q_OBJECT

private:
    Ui::MainWindow ui{};
    QClipboard* clipboard{QGuiApplication::clipboard()};
//    QStringListModel* model{};
    ClipboardEntryModel* clipboardEntryModel{};
    QStringList stringList{};

public:
    explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        ui.setupUi(this);

//        model = new QStringListModel();
        clipboardEntryModel = new ClipboardEntryModel;

//        model->setStringList(stringList);
//        ui.tableView->setModel(model);
        ui.tableView->setModel(clipboardEntryModel);

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
//        stringList.append(clipboard->text());
//        model->setStringList(stringList);
        clipboardEntryModel->dataChanged
    };
};


#endif //PASTEANDELASTE_MAINWINDOW_H
