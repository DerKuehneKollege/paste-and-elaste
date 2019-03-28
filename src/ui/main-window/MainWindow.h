#ifndef PASTEANDELASTE_MAINWINDOW_H
#define PASTEANDELASTE_MAINWINDOW_H




#include <QDebug>
#include <QClipboard>
#include <QMainWindow>
#include <QStringListModel>
#include <QMessageBox>

#include "UiMainWindow.h"
#include "src/consts.h"
#include "src/model/ClipboardEntryModel.h"

namespace Pae {
    static const int COLUMN_TIMESTAMP_WIDTH_PX = 150;
}

class MainWindow : public QMainWindow {
Q_OBJECT

private:
    Ui::MainWindow ui{};
    QClipboard* clipboard{nullptr};
    ClipboardEntryModel* clipboardEntryModel{new ClipboardEntryModel};

public:
    explicit MainWindow(QWidget *parent, QClipboard *clipboard)
        : QMainWindow(parent), clipboard(clipboard)
    {
        ui.setupUi(this);

        ui.tableView->setModel(clipboardEntryModel);
        ui.tableView->horizontalHeader()->setSectionResizeMode(Pae::COLUMN_DATA, QHeaderView::Stretch);
        ui.tableView->horizontalHeader()->setSectionResizeMode(Pae::COLUMN_TIMESTAMP, QHeaderView::Fixed);
        ui.tableView->setColumnWidth(Pae::COLUMN_TIMESTAMP, Pae::COLUMN_TIMESTAMP_WIDTH_PX);

        QObject::connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(onSearchButtonClick()));
        QObject::connect(ui.actionInfo, SIGNAL(triggered()), this, SLOT(onInfoActionTriggered()));
        QObject::connect(ui.actionBeenden, SIGNAL(triggered()), this, SLOT(onCloseActionTriggered()));

        QObject::connect(ui.tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onTableViewDoubleClicked(const QModelIndex&)));

        QObject::connect(clipboard, SIGNAL(dataChanged()), this, SLOT(onClipboardDataChanged()));
    }

protected:
    void closeEvent(QCloseEvent *event) override {
        qInfo() << "Program about to close.";
    }

private slots:
    void onSearchButtonClick() {
        qDebug() << "Search button clicked.";
    };

    void onInfoActionTriggered() {
        qDebug() << "Info action triggered.";
        QMessageBox::about(this, "PasteAndElaste", "Ein Programm zur Verwaltung der Zwischenablage.\n(c) 2019 Martin Kühn");
    };

    void onCloseActionTriggered() {
        qDebug() << "Close action triggered.";
        close();
    }

    void onTableViewDoubleClicked(const QModelIndex &index) {
        auto selectedData = clipboardEntryModel->data(index, Qt::DisplayRole);
        qDebug() << "Double clicked table, text is: [" << selectedData << "]";
        // FIXME before copying data, unassigned clipboard event to avoid duplication of copied item
        clipboard->setText(selectedData.toString());
    }

    void onClipboardDataChanged() {
        qDebug() << "Clipboard-Data changed, clipboard text is: [" << clipboard->text() << "]";

        auto *newEntry = new ClipboardEntry;
        newEntry->setData(clipboard->text());
        newEntry->setTimestamp(QDateTime::currentDateTime());

        clipboardEntryModel->addEntry(newEntry);
        ui.tableView->resizeRowsToContents();
    };
};


#endif //PASTEANDELASTE_MAINWINDOW_H
