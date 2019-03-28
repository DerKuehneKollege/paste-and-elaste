//
// Created by mumpi on 27.03.2019.
//

#ifndef PASTEANDELASTE_CLIPBOARDENTRY_H
#define PASTEANDELASTE_CLIPBOARDENTRY_H

#include <QObject>
#include <QVariant>
#include <QDateTime>

class ClipboardEntry : public QObject {
    Q_OBJECT

private:
    QVariant mData{};
    QDateTime mTimestamp{};

public:
    ClipboardEntry() = default;

    inline const QVariant &getData() const {
        return mData;
    }

    inline void setData(const QVariant &data) {
        mData = data;
    }

    inline const QDateTime &getTimestamp() const {
        return mTimestamp;
    }

    inline void setTimestamp(const QDateTime &timestamp) {
        mTimestamp = timestamp;
    }
};


#endif //PASTEANDELASTE_CLIPBOARDENTRY_H
