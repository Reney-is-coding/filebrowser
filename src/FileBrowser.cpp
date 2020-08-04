#include "../include/FileBrowser.h"

FileBrowser::FileBrowser(const QString &filter, QWidget *parent, const char *name)
        : QListWidget(parent)
{
    m_nameFilter = filter;
    setDir(QDir::currentPath());
    connect(this, &FileBrowser::itemChanged, this, &FileBrowser::itemHighlighted);
    connect(this, &FileBrowser::itemDoubleClicked, this, &FileBrowser::itemSelected);
}

void FileBrowser::setDir(const QString &path)
{
    QDir dir(path, m_nameFilter, QDir::DirsFirst);
    if (!dir.isReadable())
        return;
    clear();

    QStringList entries = dir.entryList();
    QStringList::ConstIterator it = entries.constBegin();
    while (it != entries.constEnd()) {
        if (*it != ".")
            insertItem(1, *it);
        ++it;
    }
    m_basePath = dir.canonicalPath();
}

void FileBrowser::itemHighlighted(QListWidgetItem *item)
{
    QString path = m_basePath + "/" + item->text();
    if (QFileInfo(path).isFile()) {
        QUrl temp(path);
        emit picked(temp);
    }
}

void FileBrowser::itemSelected(QListWidgetItem *item)
{
    QString path = m_basePath + "/" + item->text();
    if (QFileInfo(path).isDir())
        setDir(path);
}
