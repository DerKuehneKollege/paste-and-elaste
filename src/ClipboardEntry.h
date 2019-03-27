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
public:
    inline const QVariant &getData() const {
        return data;
    }

    inline void setData(const QVariant &data) {
        ClipboardEntry::data = data;
    }

    inline const QDateTime &getTimestamp() const {
        return timestamp;
    }

    inline void setTimestamp(const QDateTime &timestamp) {
        ClipboardEntry::timestamp = timestamp;
    }

private:
    QVariant data;
    QDateTime timestamp;
};


#endif //PASTEANDELASTE_CLIPBOARDENTRY_H
