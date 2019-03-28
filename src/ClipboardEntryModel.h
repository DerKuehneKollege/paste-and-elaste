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

private:
    QList<ClipboardEntry*> entries;

public:
    explicit ClipboardEntryModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
    }

    void addEntry(ClipboardEntry *pEntry) {
        const int begin = entries.size() > 0 ? entries.size() - 1 : 0;
        const int last = entries.size();
        beginInsertRows(QModelIndex(), begin, last);
        entries.push_back(pEntry);
        endInsertRows();
//        QModelIndex topLeft = createIndex(entries.size() - 1, 0);
//        QModelIndex bottomRight = createIndex(entries.size(), 1);
//        emit dataChanged(topLeft, bottomRight, {Qt::DisplayRole});
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return entries.length();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return NUM_COLUMNS;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Data");
                case 1:
                    return QString("Timestamp");
            }
        }

        return QVariant();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole) {
            if (index.column() == 0) {
                return entries.at(index.row())->getData();
            } else {
                return entries.at(index.row())->getTimestamp();
            }
        }

        return QVariant();
    }

};


#endif //PASTEANDELASTE_CLIPBOARDENTRYMODEL_H
