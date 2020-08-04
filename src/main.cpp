#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextBrowser>
#include <QSplitter>
#include <QObject>

#include "include/FileBrowser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSplitter win(Qt::Horizontal);

    FileBrowser *fileBrowser = new FileBrowser("*", &win);
    QTextBrowser *textBrowser = new QTextBrowser(&win);
    QObject::connect(fileBrowser, &FileBrowser::picked,
                     textBrowser, &QTextBrowser::setSource);

    win.show();
    return app.exec();
}
