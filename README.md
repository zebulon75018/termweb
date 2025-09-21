# TERMWEB

This is an C++/QT5 application join a terminal and the QWebEngine

You must clone 3 repository:

* QSingleInstance  https://github.com/Skycoder42/QSingleInstance
* qtterminalwidget  : https://github.com/jacob3141/qtterminalwidget
* inja : https://github.com/pantor/inja

 Please patch the QSingleInstance :

 QSingleInstance/QSingleInstance/qsingleinstance_p.cpp
```
 void QSingleInstancePrivate::clientConnected()
{
        lockdownTimer->start();
        QStringList arg ;
        arg << QDir::currentPath();  // ADD THIS ONE 
        foreach (QString a ,QCoreApplication::arguments())
        {
          arg << a;
        }
        //performSend(QCoreApplication::arguments());
        performSend(arg);
}
```
# ScreenShot 
![](https://github.com/zebulon75018/termweb/blob/5c45f44a2f9a0fb193cf33079dc1488375660ee8/img/termwebman.png)

![](https://github.com/zebulon75018/termweb/blob/5c45f44a2f9a0fb193cf33079dc1488375660ee8/img/termwebdiffpicture.png))

