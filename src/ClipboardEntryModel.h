//
// Created by mumpi on 27.03.2019.
//

#ifndef PASTEANDELASTE_CLIPBOARDENTRYMODEL_H
#define PASTEANDELASTE_CLIPBOARDENTRYMODEL_H


static const int NUM_COLUMNS = 2;

#include <QAbstractTableModel>
#include "ClipboardEntry.h"

class ClipboardEntryModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit ClipboardEntryModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
        entries = new QList<ClipboardEntry>();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return entries->length();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return NUM_COLUMNS;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole) {
            if (index.column() == 0) {
                return entries->at(index.row()).getData();
            } else {
                return entries->at(index.row()).getTimestamp();
            }
        }

        return QVariant();
    }

private:
    QList<ClipboardEntry> *entries;
};


#endif //PASTEANDELASTE_CLIPBOARDENTRYMODEL_H
