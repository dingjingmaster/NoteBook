#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>
#include <QString>
#include <QFile>        //文件输入输出
#include <QFileDialog>      //文件对话框
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include "ui_notebook.h"
#include "setting.h"
#include "configinfo.h"

namespace Ui
{
class NoteBook;
}

class NoteBook : public QMainWindow
{
    Q_OBJECT

private:
    Ui::NoteBook *ui;
    Setting* setAction;

    Color color;
    QPalette palette;

    //主窗体中的参数；
    QString fileName;
    int setWindowsClarity;        //透明度设置；
    QFont setMainTextFont;          //字体设置；
    int setMainTextSize;            //设置字体大小；
    bool setMainTextBold;       //设置字体加粗；
    bool setMainTextItalic;         //设置字体倾斜；
    int setMainTextColorIndex;
    int setMainWindowBackColorIndex;
    QColor setMainTextColor;
    QColor setMainWindowBackColor;

public:
    explicit NoteBook(QWidget *parent = 0);

    //初始化函数；
private:
    void Init_Set();
    void Init_Connection();
    void Read_Info();
    void Set_Info();
    void Get_Color(int setMainTextColorIndex , int setMainWindowBackColorIndex);

private slots:
    void fileNewAction_Triggered();
    void fileOpenAction_Triggered();
    void fileSaveAction_Triggered();
    void fileSaveOtherAction_Triggered();
    void fileExitAction_Triggered();

    //
    void mainAboutSetAction_Triggered();
    //设置实现；
    void setWindowsClarityButton_Clicked(QString fileName ,int setWindowsClarity, QFont setMainTextFont, int setMainTextSize,bool setMainTextBold, bool setMainTextItalic, int setMainTextColor, int setMainWindowBackColor);

public:
    ~NoteBook();

};


#endif // NOTEBOOK_H
