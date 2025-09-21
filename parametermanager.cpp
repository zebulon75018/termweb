#include <QDebug>
#include <QDir>
#include "parametermanager.h"

parameterManager::parameterManager(QStringList params)
{
  //qDebug() << params;
  //cwd = QDir::currentPath();
  if (params.length() == 0 ) 
  {
    return;
  }
  // Hack with is the cwd from the singleinstance client.
  cwd = params[0];
  // remove the first element ( program .. )
  params.removeAt(1);
  for (int n = 0; n< params.length();n++) {
     //qDebug() << params[n];
     if ( params[n].toLower() =="-h" || params[n].toLower() == "--help") 
      { 

         //qDebug() << " help ";
         mode = Mode::Help;
         return;
       }
       if ( params[n] =="open") {
           mode = Mode::Open;
           if (params.length() >n +1)
           {
               nameParam = params [n+1];
           }
       }

      if ( params[n] =="man") {
         mode = Mode::Man;
         if (params.length() >n +1)
         {
            nameParam = params [n+1];
         }
      }
      if ( params[n] =="edit") {
          if (params.length() >n +1)
          {
            nameFileToEdit = params[n+1];
            mode = Mode::Edit;
          } else {
              qDebug() << " filename missing ";
          }
      }
      if ( params[n] =="diff") {
          //qDebug() << " diff ";
          if (params.length() >n+2)
          {
            nameFileToEdit = params[n+1];
            nameFileToEdit2 = params[n+2];
            mode = Mode::Diff;
            //qDebug() << nameFileToEdit << " " << nameFileToEdit2;
          } else {
              qDebug() << " filenames missing ";
          }

      }
      if ( params[n] =="view") {
          if (params.length() >n +1)
          {
            nameFileToEdit = params[n+1];
            mode = Mode::View;
          }
     }
      if ( params[n] =="js") {
          if (params.length() >n +1)
          {
              nameFileToEdit = params[n+1];
              mode = Mode::Js;
          }
      }
     // Name of tab terminal
      if ( params[n] =="name") {
          if (params.length() >n +1)
          {
              nameDock = params[n+1];
              //qDebug() << " NAME " << nameDock;
              mode = Mode::Shell;
              //DockerRegistry.self();
        }
      }
     if ( params[n] =="bookmark") {
         mode = Mode::Bookmark;
         if (params.length() >n +1)
         {
            nameParam = params [n+1];
         }
      }

  }
}

QString parameterManager::getExtension(const QString& filenameOrExtension)
{
    QString ext = QFileInfo(filenameOrExtension).suffix().toLower();
    return ext;

}



bool parameterManager::isHelpRequest()
{
  return mode == Mode::Help;
}

bool parameterManager::isBookmarkRequest()
{
  return mode == Mode::Bookmark;
}


void parameterManager::showHelp()
{
    qInfo() <<  " name ";
    qInfo() <<  " man ";
    qInfo() <<  " edit [file] ";
    qInfo() <<  " view [file] ";
    qInfo() <<  " diff [file1] [file2] ";
}


/****
 *
 * File type management.
 *
 ****/
QString parameterManager::fromExtension(const QString& filenameOrExtension)
{
    QString ext = QFileInfo(filenameOrExtension).suffix().toLower();

    static QHash<QString, QString> extToLang = parameterManager::initMapping();
    return extToLang.value(ext, "plaintext");
}

bool parameterManager::isImage(const QString& filenameOrExtension)
{
   QString ext = parameterManager::getExtension(filenameOrExtension);
    return parameterManager::extensionImage().contains(ext);
}

bool parameterManager::isVideo(const QString& filenameOrExtension)
{
    QString ext = parameterManager::getExtension(filenameOrExtension);
    return parameterManager::extensionMovieMusic().contains(ext);
}


bool parameterManager::isHtml(const QString& filenameOrExtension)
{
    QString ext = parameterManager::getExtension(filenameOrExtension);
    return ( ext == "html" || ext == "htm" ) ;

}

/*******************************************************************/

QStringList  parameterManager::extensionMovieMusic()
{
    QStringList movieext;
    movieext <<  "mov" << "mp4" << "mpg" <<"mpeg" <<"ogg" <<"wav"<<"mp3" ;
    return movieext;
}

QStringList  parameterManager::extensionImage()
{
    QStringList imgext;
    imgext  <<   "jpg" << "jpeg" << "png" <<"webp" ;
    return imgext;
}


QHash<QString, QString> parameterManager::initMapping()
{
    return {
        { "cpp", "cpp" },
            { "c", "c" },
            { "h", "cpp" },
            { "hpp", "cpp" },
            { "py", "python" },
            { "js", "javascript" },
            { "ts", "typescript" },
            { "json", "json" },
            { "html", "html" },
            { "htm", "html" },
            { "css", "css" },
            { "java", "java" },
            { "cs", "csharp" },
            { "xml", "xml" },
            { "yaml", "yaml" },
            { "yml", "yaml" },
            { "md", "markdown" },
            { "sh", "shell" },
            { "bat", "bat" },
            { "txt", "plaintext" },
            { "sql", "sql" },
            { "ini", "ini" },
            { "go", "go" },
            { "rs", "rust" },
            { "lua", "lua" },
            { "php", "php" },
            { "py", "python" },
            { "html", "html" },
            { "swift", "swift" },
            { "kt", "kotlin" },
            { "scala", "scala" },
            { "dart", "dart" }
    };
}

