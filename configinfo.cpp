#include "configinfo.h"
#include <QDebug>
#include <QFile>

ConfigInfo::ConfigInfo()
{
    Init_set();
    Open_File_Read();
}

void ConfigInfo::Init_set()
{
    fileConfigPath = new QString("./NoteBookPlus.conf");
}

void ConfigInfo::Set_Inf(QString fileName, int setWindowsClarity, int setMainTextSize, bool setMainTextBold, bool setMainTextItalic, int setMainTextColor, int setMainWindowBackColor)
{
    this ->fileName = fileName;
    this ->setWindowsClarity = setWindowsClarity;
    this ->setMainTextSize = setMainTextSize;
    this ->setMainTextBold = setMainTextBold;
    this ->setMainTextItalic = setMainTextItalic;
    this ->setMainTextColor = setMainTextColor;
    this ->setMainWindowBackColor = setMainWindowBackColor;
    Open_File_Write();
}

void ConfigInfo::Open_File_Write()
{
    QFile fileWrite(*fileConfigPath);
    fileWrite.open (QIODevice::WriteOnly | QIODevice::Text);
    QTextStream text(&fileWrite);

    text << fileName <<endl
         <<setWindowsClarity <<endl
        <<setMainTextSize <<endl
       <<setMainTextBold <<endl
      <<setMainTextItalic <<endl
     <<setMainTextColor <<endl
    <<setMainWindowBackColor<<endl;

    text.flush ();
    fileWrite.close ();
}

void ConfigInfo::Open_File_Read()
{
    bool have;
    QString buf;
    QFile fileRead(*fileConfigPath);

    have = fileRead.open (QIODevice::ReadOnly | QIODevice::Text);
    if(!have)
    {
        fileRead.open (QIODevice::WriteOnly);

        setWindowsClarity = 100;
        setMainTextSize = 30;
        setMainTextBold = false;
        setMainTextItalic = false;
        setMainTextColor = 54;
        setMainWindowBackColor = 0;
        Open_File_Write();
    }
    else
    {
        QTextStream text(&fileRead);

        buf = text.readLine (1024);
        fileName = buf;

        buf = text.readLine (1024);
        setWindowsClarity = buf.toInt ();

        buf = text.readLine (1024);
        setMainTextSize = buf.toInt ();

        buf = text.readLine (1024);
        setMainTextBold = (buf.toInt () ==1 ? true : false);

        buf = text.readLine (1024);
        setMainTextItalic = (buf.toInt () == 1 ? true : false);

        buf = text.readLine (1024);
        setMainTextColor = buf.toInt ();

        buf = text.readLine (1024);
        setMainWindowBackColor= buf.toInt ();

        text.flush ();
    }
    fileRead.close ();
}


