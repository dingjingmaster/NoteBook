#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QFont>
#include "color.h"
#include "ui_setting.h"

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

private:

    Ui::Setting *ui;
    friend class NoteBook;

    //设置主窗体的参数；
    QFont setMainTextFont;     //设置主窗口字体；
    QString fileName;
    int setWindowsClarity;       //窗口透明度；
    int setMainTextSize;               //设置字体大小；
    bool setMainTextBold;       //设置字体加粗；
    bool setMainTextItalic;         //设置字体倾斜；
    int setMainTextColor;
    int setMainWindowBackColor;

//

public:
    Setting(QWidget *parent = 0);

private:
    void Init_Connection();
    void Init_Set();
    void InIt_Setting();

    void setFontSizeComboBox();
    void setFontColorComboBox();
    void setWindowBackColorComboBox();


private slots:
    void setWindowsClarityLabel_Slot(int value);
    void settingApplyActionClicked();
    void settingOkActionClicked();
    void settingOpenFileActionClicked_Slot();

signals:
    void freshNewSetting(QString fileName , int setWindowsClarity , QFont mainTextFont, int mainTextSize,bool setMainTextBold , bool setMainTextItalic, int setMainTextColor, int setMainWindowBackColor);

public:
    ~Setting();
};

#endif // SETTING_H
