#include <QListWidget>
#include <QApplication>
#include <QObject>
#include <QDir>
#include <QUrl>

class FileBrowser : public QListWidget
{
    Q_OBJECT

public:
    FileBrowser(const QString &filter, QWidget *parent = 0, const char *name = 0);
    void setDir(const QString &path);

signals:
    void picked(const QUrl &fileName);

private slots:
    void itemHighlighted(QListWidgetItem *item);
    void itemSelected(QListWidgetItem *item);

private:
    QString m_nameFilter;
    QString m_basePath;
};
