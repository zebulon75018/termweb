#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#ifdef QT5
#include <QWebView>
#include <QWebFrame>
#endif
#ifdef QT6
//#include <QWebEngineFrame>
#include <QWebEngineView>
#endif
#include <QString>
#include <QUrl>

class parameterManager;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void commandRecieved( QStringList l);



public:
    MainWindow(QString dir, QWidget *parent = nullptr);
    ~MainWindow();
    void viewDir(QString dirname);
    void editimage(parameterManager *p, bool video =false );
    void editfile(parameterManager *p);
    void difffile(parameterManager *p);
    void diffimage(parameterManager *p, bool video = false);
void urlActived(const QUrl &u);
QString joinDir(QString dir,QString subdir);
void saveFile(QString filename,QString& content);
QString readFile(QString filename);


private:
   QString appdir;
#ifdef QT5
   QWebView *wv;
   QWebPage *wp;
#endif
#ifdef QT6
   QWebEngineView *wv;
   QWebEnginePage *wp;
#endif

};
#endif // MAINWINDOW_H
