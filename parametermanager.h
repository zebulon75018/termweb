#ifndef PARAMETERMANAGER_H
#define PARAMETERMANAGER_H

#include <QStringList>

class parameterManager
{
public:
  enum class Mode {
        None,        
        Man,
        Edit,
        View,
        Diff,
        Open,        
        Js,
        Savehtml,
        Help
    };

    parameterManager(QStringList param);
    bool isHelpRequest(); 
    void showHelp();

    static QString fromExtension(const QString& filenameOrExtension);
    static bool isVideo(const QString& filenameOrExtension);
    static bool isImage(const QString& filenameOrExtension);
    static bool isMarkdown(const QString& filenameOrExtension);
    static bool isHtml(const QString& filenameOrExtension);
    static QStringList extensionMovieMusic();
    static QStringList extensionImage();


   /***************************/  
    Mode mode = Mode::None;
    bool createintab = false;
    QString nameParam; // Name of param for man and bookmark , and javascript
    QString nameFileToEdit;
    QString nameFileToEdit2;
    QString cwd; // Current  Working Directory

private:
    static QHash<QString, QString> initMapping();
    static QString getExtension(const QString& filenameOrExtension);
};

#endif // PARAMETERMANAGER_H
