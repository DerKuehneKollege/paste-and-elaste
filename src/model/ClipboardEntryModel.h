//
// Created by mumpi on 27.03.2019.
//

#ifndef PASTEANDELASTE_CLIPBOARDENTRYMODEL_H
#define PASTEANDELASTE_CLIPBOARDENTRYMODEL_H

namespace Pae {
    static const int NUM_COLUMNS = 2;
    static const char *const TABLE_TIMESTAMP_FORMAT = "d.M.yyyy hh:mm:ss.z";
}

#include <QDebug>
#include <QAbstractTableModel>
#include "ClipboardEntry.h"

class ClipboardEntryModel : public QAbstractTableModel {
    Q_OBJECT

private:
    QList<ClipboardEntry*> mEntries{};

public:
    explicit ClipboardEntryModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
    }

    void addEntry(ClipboardEntry *newEntry) {
        const int lastPosition = mEntries.empty()
                ? 0
                : mEntries.size() - 1;

        beginInsertRows(QModelIndex(), lastPosition, lastPosition);
        mEntries.push_back(newEntry);
        endInsertRows();
    }

    int rowCount(const QModelIndex &parent) const override {
        return mEntries.length();
    }

    int columnCount(const QModelIndex &parent) const override {
        return Pae::NUM_COLUMNS;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return tr("Data");
                case 1:
                    return tr("Timestamp");
                default:
                    qWarning() << "ClipboardEntryModel::headerData: Num columns exceeded [" << section << "]";
            }
        }

        return QVariant();
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (role == Qt::DisplayRole) {
            if (index.column() == 0) {
                return mEntries.at(index.row())->getData();
            } else {
                return mEntries.at(index.row())->getTimestamp().toString(Pae::TABLE_TIMESTAMP_FORMAT);
            }
        }

        return QVariant();
    }

};


#endif //PASTEANDELASTE_CLIPBOARDENTRYMODEL_H
