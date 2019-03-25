//
// Created by mumpi on 25.03.2019.
//

#ifndef PASTEANDELASTE_CLIPBOARDADAPTER_H
#define PASTEANDELASTE_CLIPBOARDADAPTER_H

#include <QDebug>
#include <QtGui/QClipboard>
#include <QtGui/QGuiApplication>

class ClipboardAdapter : public QObject {
Q_OBJECT

private:
    QClipboard *clipboard;

public:
    ClipboardAdapter() {
        this->clipboard = QGuiApplication::clipboard();
        this->attach();
    }

protected slots:
    inline void onClipboardDataChanged() {
        qDebug() << "Clipboard-Data changed!";
        qDebug() << "Clipboard-Text: [" << this->clipboard->text() << "]";
    };

private:
    inline void attach() {
        QObject::connect(clipboard, SIGNAL(dataChanged()), this, SLOT(onClipboardDataChanged()));
    }

};


#endif //PASTEANDELASTE_CLIPBOARDADAPTER_H
