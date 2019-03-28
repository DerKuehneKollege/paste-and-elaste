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
    ClipboardEntry() = default;

    ClipboardEntry(ClipboardEntry &source) {
        this->data = source.data;
        this->timestamp = source.timestamp;
    }

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
