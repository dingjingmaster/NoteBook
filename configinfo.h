#ifndef CONFIGINFO_H
#define CONFIGINFO_H

#include <QString>
#include <QFont>
#include <QColor>
#include <QDir>

class ConfigInfo
{
public:
    ConfigInfo();
    //属性；
private:
    friend class NoteBook;
    friend class Setting;
    //主窗口属性；
    QString fileName;
    int setWindowsClarity;        //透明度设置；
    QFont setMainTextFont;          //字体设置；
    int setMainTextSize;            //设置字体大小；
    bool setMainTextBold;       //设置字体加粗；
    bool setMainTextItalic;         //设置字体倾斜；
    int setMainTextColor;
    int setMainWindowBackColor;

    //本类属性；
    QString* fileConfigPath;


private:
    void Init_set();
    void Set_Inf(QString fileName,
                 int setWindowsClarity,
                 int setMainTextSize,
                 bool setMainTextBold,
                 bool setMainTextItalic,
                 int setMainTextColor,
                 int setMainWindowBackColor);

    void Open_File_Write();
    void Open_File_Read();

};

#endif // CONFIGINFO_H
