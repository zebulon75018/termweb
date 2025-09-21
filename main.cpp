#include "mainwindow.h"
#include "QSingleInstance/qsingleinstance.h"
#include "parametermanager.h"

#include <QApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);

    QString cwd = QDir::currentPath();
    QStringList cmd;
    for( int n = 0; n< argc; n++)
    {
      cmd << QString(argv[n]);
    }
    auto p = new parameterManager(cmd);
    qDebug() <<  p->isHelpRequest() ;
    if ( p->isHelpRequest() ) 
    {
        p->showHelp();
        exit(0);
    }

    QSingleInstance instance;

    instance.setAutoRecovery(true);

    MainWindow *w= nullptr;

    instance.setStartupFunction([&]() -> int {
                w = new MainWindow( a.applicationDirPath() );
                w->show();
                return 0;
    });

    QObject::connect(&instance, &QSingleInstance::instanceMessage, [&](QStringList args){
                  if (w)  {
                        w->commandRecieved(args);
                       } else {
                          exit(0);
                       }
	});

    return instance.singleExec();
}
