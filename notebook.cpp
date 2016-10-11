#include "notebook.h"

NoteBook::NoteBook(QWidget* parent) : QMainWindow(parent), ui(new Ui::NoteBook)
{    
    ui->setupUi(this);
    //设置初始化；
    Init_Set();
    //链接初始化；
    Init_Connection();
    Read_Info();
    Set_Info();
    ConfigInfo info;
}

void NoteBook::Init_Connection()
{
    connect(ui ->fileNewAction , &QAction:: triggered, this, &NoteBook::fileNewAction_Triggered );
    connect(ui ->fileOpenAction , &QAction:: triggered, this, &NoteBook::fileOpenAction_Triggered);
    connect(ui ->fileSaveAction , &QAction:: triggered, this, &NoteBook::fileSaveAction_Triggered );
    connect(ui ->fileSaveOtherAction , &QAction:: triggered, this, &NoteBook::fileSaveOtherAction_Triggered );
    connect(ui ->fileExitAction , &QAction:: triggered, this, &NoteBook::fileExitAction_Triggered );

    //
    connect (ui ->setSetingAction, &QAction::triggered , this, &NoteBook::mainAboutSetAction_Triggered );
    //
    connect (setAction, &Setting::freshNewSetting, this , &NoteBook::setWindowsClarityButton_Clicked );

}

void NoteBook::Read_Info()
{
    //除了文字都保存了；
    ConfigInfo Info;
    this ->fileName = Info.fileName;
    this ->setWindowsClarity = Info.setWindowsClarity;
    this ->setMainTextSize = Info.setMainTextSize;
    this ->setMainTextBold = Info.setMainTextBold;
    this ->setMainTextItalic = Info.setMainTextItalic;
    this ->setMainTextColorIndex = Info.setMainTextColor;
    this ->setMainWindowBackColorIndex = Info.setMainWindowBackColor;
}

void NoteBook::Set_Info()
{
    this ->setMainTextFont.setBold (this ->setMainTextBold);
    this ->setMainTextFont.setItalic (this ->setMainTextItalic);
    this ->setMainTextFont.setPointSize (this ->setMainTextSize);
    ui ->mainTextEdit ->setCurrentFont (this ->setMainTextFont);   //设置字体；

    this ->Get_Color (setMainTextColorIndex , setMainWindowBackColorIndex );

    ui ->mainTextEdit ->setTextColor (setMainTextColor);

    ui ->mainTextEdit ->setAutoFillBackground (true);
    palette.setColor (QPalette::Base, this ->setMainWindowBackColor);
    ui ->mainTextEdit ->setPalette (palette);

    setWindowOpacity ((this ->setWindowsClarity)/100.0);  //设置主窗体透明度；

    //setting 对话框设置;
    setAction ->ui ->setWindowsClaritySlider ->setSliderPosition (setWindowsClarity);
    setAction ->ui ->setWindowsClarityLabel ->setText (QString::number (setWindowsClarity));

    setAction ->ui ->setFontSizeComboBox ->setCurrentIndex (setMainTextSize - 6);
    setAction ->ui ->setFontBold ->setCheckState (setMainTextBold == 1 ? Qt::CheckState::Checked : Qt::CheckState ::Unchecked);
    setAction ->ui ->setFontItalic ->setCheckState (setMainTextItalic == 1 ? Qt::CheckState::Checked : Qt::CheckState ::Unchecked);
    setAction ->ui ->setFontColorComboBox ->setCurrentIndex (setMainTextColorIndex );
    setAction ->ui ->setBackGroundColorComboBox ->setCurrentIndex (setMainWindowBackColorIndex);
    setAction ->ui ->DefaultPath->setText (fileName);
}

void NoteBook::Get_Color(int setMainTextColor , int setMainWindowBackColorIndex)
{
    switch (setMainTextColor)
    {
    case 0 :
    {
        this ->setMainTextColor = color.White ();
        break;
    }
    case 1 :
    {
        this ->setMainTextColor = color.Pink ();
        break;
    }
    case 2 :
    {
        this ->setMainTextColor = color.Crimson ();
        break;
    }
    case 3 :
    {
        this ->setMainTextColor = color.LavenderBlush ();
        break;
    }
    case 4 :
    {
        this ->setMainTextColor = color.PaleVioletRed ();
        break;
    }
    case 5 :
    {
        this ->setMainTextColor = color.HotPink ();
        break;
    }
    case 6 :
    {
        this ->setMainTextColor = color.DeepPink ();
        break;
    }
    case 7 :
    {
        this ->setMainTextColor = color.MediumVioletRed ();
        break;
    }
    case 8 :
    {
        this ->setMainTextColor = color.Orchid ();
        break;
    }
    case 9 :
    {
        this ->setMainTextColor = color.Thistle ();
        break;
    }
    case 10 :
    {
        this ->setMainTextColor = color.plum ();
        break;
    }
    case 11 :
    {
        this ->setMainTextColor = color.Violet ();
        break;
    }
    case 12 :
    {
        this ->setMainTextColor = color.Magenta ();
        break;
    }
    case 13 :
    {
        this ->setMainTextColor = color.Fuchsia ();
        break;
    }
    case 14 :
    {
        this ->setMainTextColor = color.DarkMagenta ();
        break;
    }
    case 15 :
    {
        this ->setMainTextColor = color.Purple ();
        break;
    }
    case 16 :
    {
        this ->setMainTextColor = color.MediumOrchid ();
        break;
    }
    case 17 :
    {
        this ->setMainTextColor = color.DarkVoilet ();
        break;
    }
    case 18 :
    {
        this ->setMainTextColor = color.DarkOrchid ();
        break;
    }
    case 19 :
    {
        this ->setMainTextColor = color.Indigo ();
        break;
    }
    case 20 :
    {
        this ->setMainTextColor = color.BlueViolet ();
        break;
    }
    case 21 :
    {
        this ->setMainTextColor = color.MediumPurple ();
        break;
    }
    case 22 :
    {
        this ->setMainTextColor = color.MediumSlateBlue ();
        break;
    }
    case 23 :
    {
        this ->setMainTextColor = color.SlateBlue ();
        break;
    }
    case 24 :
    {
        this ->setMainTextColor = color.DarkSlateBlue ();
        break;
    }
    case 25 :
    {
        this ->setMainTextColor = color.Lavender ();
        break;
    }
    case 26 :
    {
        this ->setMainTextColor = color.GhostWhite ();
        break;
    }
    case 27 :
    {
        this ->setMainTextColor = color.Blue ();
        break;
    }
    case 28 :
    {
        this ->setMainTextColor = color.MediumBlue ();
        break;
    }
    case 29 :
    {
        this ->setMainTextColor = color.MidnightBlue ();
        break;
    }
    case 30 :
    {
        this ->setMainTextColor = color.DarkBlue ();
        break;
    }
    case 31 :
    {
        this ->setMainTextColor = color.Navy ();
        break;
    }
    case 32 :
    {
        this ->setMainTextColor = color.RoyalBlue ();
        break;
    }
    case 33 :
    {
        this ->setMainTextColor = color.CornflowerBlue ();
        break;
    }
    case 34 :
    {
        this ->setMainTextColor = color.LightSteelBlue ();
        break;
    }
    case 35 :
    {
        this ->setMainTextColor = color.LightSlateGray ();
        break;
    }
    case 36 :
    {
        this ->setMainTextColor = color.DoderBlue ();
        break;
    }
    case 37 :
    {
        this ->setMainTextColor = color.AliceBlue ();
        break;
    }
    case 38 :
    {
        this ->setMainTextColor = color.LightSkyBlue ();
        break;
    }
    case 39 :
    {
        this ->setMainTextColor = color.DeepSkyBlue ();
        break;
    }
    case 40 :
    {
        this ->setMainTextColor = color.Cyan ();
        break;
    }
    case 41 :
    {
        this ->setMainTextColor = color.MediumSpringGreen ();
        break;
    }
    case 42 :
    {
        this ->setMainTextColor = color.MintCream ();
        break;
    }
    case 43 :
    {
        this ->setMainTextColor = color.SpringGreen ();
        break;
    }
    case 44 :
    {
        this ->setMainTextColor = color.Lime ();
        break;
    }
    case 45 :
    {
        this ->setMainTextColor = color.Ivory ();
        break;
    }
    case 46 :
    {
        this ->setMainTextColor = color.LightYellow ();
        break;
    }
    case 47 :
    {
        this ->setMainTextColor = color.PaleGodenrod ();
        break;
    }
    case 48 :
    {
        this ->setMainTextColor = color.Orange ();
        break;
    }
    case 49 :
    {
        this ->setMainTextColor = color.Moccasin ();
        break;
    }
    case 50 :
    {
        this ->setMainTextColor = color.LightSalmon ();
        break;
    }
    case 51 :
    {
        this ->setMainTextColor = color.OrangeRed ();
        break;
    }
    case 52 :
    {
        this ->setMainTextColor = color.Salmon ();
        break;
    }
    case 53 :
    {
        this ->setMainTextColor = color.Red ();
        break;
    }
    case 54 :
    {
        this ->setMainTextColor = color.Black ();
        break;
    }
    default:
    {
        this ->setMainTextColor = color.Black ();
    }
    }

    switch (setMainWindowBackColorIndex)
    {
    case 0 :
    {
        this ->setMainWindowBackColor = color.White ();
        break;
    }
    case 1 :
    {
        this ->setMainWindowBackColor = color.Pink ();
        break;
    }
    case 2 :
    {
        this ->setMainWindowBackColor = color.Crimson ();
        break;
    }
    case 3 :
    {
        this ->setMainWindowBackColor = color.LavenderBlush ();
        break;
    }
    case 4 :
    {
        this ->setMainWindowBackColor = color.PaleVioletRed ();
        break;
    }
    case 5 :
    {
        this ->setMainWindowBackColor = color.HotPink ();
        break;
    }
    case 6 :
    {
        this ->setMainWindowBackColor = color.DeepPink ();
        break;
    }
    case 7 :
    {
        this ->setMainWindowBackColor = color.MediumVioletRed ();
        break;
    }
    case 8 :
    {
        this ->setMainWindowBackColor = color.Orchid ();
        break;
    }
    case 9 :
    {
        this ->setMainWindowBackColor = color.Thistle ();
        break;
    }
    case 10 :
    {
        this ->setMainWindowBackColor = color.plum ();
        break;
    }
    case 11 :
    {
        this ->setMainWindowBackColor = color.Violet ();
        break;
    }
    case 12 :
    {
        this ->setMainWindowBackColor = color.Magenta ();
        break;
    }
    case 13 :
    {
        this ->setMainWindowBackColor = color.Fuchsia ();
        break;
    }
    case 14 :
    {
        this ->setMainWindowBackColor = color.DarkMagenta ();
        break;
    }
    case 15 :
    {
        this ->setMainWindowBackColor = color.Purple ();
        break;
    }
    case 16 :
    {
        this ->setMainWindowBackColor = color.MediumOrchid ();
        break;
    }
    case 17 :
    {
        this ->setMainWindowBackColor = color.DarkVoilet ();
        break;
    }
    case 18 :
    {
        this ->setMainWindowBackColor = color.DarkOrchid ();
        break;
    }
    case 19 :
    {
        this ->setMainWindowBackColor = color.Indigo ();
        break;
    }
    case 20 :
    {
        this ->setMainWindowBackColor = color.BlueViolet ();
        break;
    }
    case 21 :
    {
        this ->setMainWindowBackColor = color.MediumPurple ();
        break;
    }
    case 22 :
    {
        this ->setMainWindowBackColor = color.MediumSlateBlue ();
        break;
    }
    case 23 :
    {
        this ->setMainWindowBackColor = color.SlateBlue ();
        break;
    }
    case 24 :
    {
        this ->setMainWindowBackColor = color.DarkSlateBlue ();
        break;
    }
    case 25 :
    {
        this ->setMainWindowBackColor = color.Lavender ();
        break;
    }
    case 26 :
    {
        this ->setMainWindowBackColor = color.GhostWhite ();
        break;
    }
    case 27 :
    {
        this ->setMainWindowBackColor = color.Blue ();
        break;
    }
    case 28 :
    {
        this ->setMainWindowBackColor = color.MediumBlue ();
        break;
    }
    case 29 :
    {
        this ->setMainWindowBackColor = color.MidnightBlue ();
        break;
    }
    case 30 :
    {
        this ->setMainWindowBackColor = color.DarkBlue ();
        break;
    }
    case 31 :
    {
        this ->setMainWindowBackColor = color.Navy ();
        break;
    }
    case 32 :
    {
        this ->setMainWindowBackColor = color.RoyalBlue ();
        break;
    }
    case 33 :
    {
        this ->setMainWindowBackColor = color.CornflowerBlue ();
        break;
    }
    case 34 :
    {
        this ->setMainWindowBackColor = color.LightSteelBlue ();
        break;
    }
    case 35 :
    {
        this ->setMainWindowBackColor = color.LightSlateGray ();
        break;
    }
    case 36 :
    {
        this ->setMainWindowBackColor = color.DoderBlue ();
        break;
    }
    case 37 :
    {
        this ->setMainWindowBackColor = color.AliceBlue ();
        break;
    }
    case 38 :
    {
        this ->setMainWindowBackColor = color.LightSkyBlue ();
        break;
    }
    case 39 :
    {
        this ->setMainWindowBackColor = color.DeepSkyBlue ();
        break;
    }
    case 40 :
    {
        this ->setMainWindowBackColor = color.Cyan ();
        break;
    }
    case 41 :
    {
        this ->setMainWindowBackColor = color.MediumSpringGreen ();
        break;
    }
    case 42 :
    {
        this ->setMainWindowBackColor = color.MintCream ();
        break;
    }
    case 43 :
    {
        this ->setMainWindowBackColor = color.SpringGreen ();
        break;
    }
    case 44 :
    {
        this ->setMainWindowBackColor = color.Lime ();
        break;
    }
    case 45 :
    {
        this ->setMainWindowBackColor = color.Ivory ();
        break;
    }
    case 46 :
    {
        this ->setMainWindowBackColor = color.LightYellow ();
        break;
    }
    case 47 :
    {
        this ->setMainWindowBackColor = color.PaleGodenrod ();
        break;
    }
    case 48 :
    {
        this ->setMainWindowBackColor = color.Orange ();
        break;
    }
    case 49 :
    {
        this ->setMainWindowBackColor = color.Moccasin ();
        break;
    }
    case 50 :
    {
        this ->setMainWindowBackColor = color.LightSalmon ();
        break;
    }
    case 51 :
    {
        this ->setMainWindowBackColor = color.OrangeRed ();
        break;
    }
    case 52 :
    {
        this ->setMainWindowBackColor = color.Salmon ();
        break;
    }
    case 53 :
    {
        this ->setMainWindowBackColor = color.Red ();
        break;
    }
    case 54 :
    {
        this ->setMainWindowBackColor = color.Black ();
        break;
    }
    default:
    {
        this ->setMainWindowBackColor = color.White ();
    }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void NoteBook::Init_Set()
{
    setAction = new Setting(this);
    setWindowIcon (QIcon(":/new/prefix1/source/picture/35.png"));
    //窗体透明度设置；
    setWindowOpacity (1);
}

void NoteBook::fileNewAction_Triggered()
{
    fileOpenAction_Triggered();         //待完善；
}

void NoteBook::fileOpenAction_Triggered()
{
    //getExistingDirectory()提供用户选择目录   第一个参数指定父类，第二个参数标题栏题目，第三个参数将已指定的目录设置为默认目录 ， 第四个参数对利用对话框的常量值进行过滤的 option值，
    //getSaveFilename()提供用户指定要保存的文件的对话框功能。

    QFileDialog::Options option;
    option = QFileDialog::ReadOnly | QFileDialog::DontResolveSymlinks;

    this ->fileName = QFileDialog :: getOpenFileName (this, tr("打开文件"),"/",tr("*;; *.txt;; *.h;; *.c;; *.cpp"), &fileName, option);
    //fileOpen = fopen(fileName.toStdString ().data (), "a+");      //文件打开，注意。C语言版本的。

    QFile fileIn (fileName);      //
    fileIn.open(QIODevice::ReadWrite | QIODevice::Text ); //| QIODevice ::Append);    //文本形式只读打开文件。（\n、\r\n）Qt的两种读写文件方式。
    QTextStream text(&fileIn);               //
    QString inBuf = text.readAll ();
    ui ->mainTextEdit->setText (inBuf);
}

void NoteBook::fileSaveAction_Triggered()
{
    QFile fileOut(fileName);
    fileOut.open (QIODevice ::WriteOnly | QIODevice ::Text  | QIODevice ::Append | QIODevice ::Truncate);
    QTextStream text(&fileOut);
    text << ui ->mainTextEdit->toPlainText ()<<endl;
}

void NoteBook::fileSaveOtherAction_Triggered()
{
    //待完善；
    QFileDialog ::Options option;
    option = QFileDialog::DontResolveSymlinks;

    this ->fileName = QFileDialog ::getOpenFileName (this, tr("另存为..."), "/", tr("*.txt;; *.h;; *.c;; *.cpp;; *"), &fileName ,option);

    fileSaveAction_Triggered ();

}

void NoteBook::fileExitAction_Triggered()
{
    close ();
}

//
void NoteBook::mainAboutSetAction_Triggered()
{
    setAction ->exec ();
}

//设置
void NoteBook::setWindowsClarityButton_Clicked(QString fileName ,int setWindowsClarity, QFont setMainTextFont, int setMainTextSize, bool setMainTextBold, bool setMainTextItalic, int setMainTextColorIndex, int setMainWindowBackColorIndex)
{
    //改变参数；
    fileName = fileName;
    this ->setWindowsClarity = setWindowsClarity;

    this ->setMainTextBold = setMainTextBold;
    this ->setMainTextItalic = setMainTextItalic;
    this ->setMainTextSize = setMainTextSize;
    this ->setMainTextFont = setMainTextFont;

    this ->setMainTextColorIndex = setMainTextColorIndex;
    this ->setMainWindowBackColorIndex = setMainWindowBackColorIndex;

    //设置改变；
    setWindowOpacity (this ->setWindowsClarity / 100.0);
    this ->setMainTextFont.setBold (this ->setMainTextBold);
    this ->setMainTextFont.setItalic (this ->setMainTextItalic);
    this ->setMainTextFont.setPointSize (this ->setMainTextSize);
    ui ->mainTextEdit ->setCurrentFont (this ->setMainTextFont);

    this ->Get_Color (setMainTextColorIndex , setMainWindowBackColorIndex );

    this ->setMainTextColor = setMainTextColor;

    ui ->mainTextEdit ->setAutoFillBackground (true);
    palette.setColor (QPalette::Base, this ->setMainWindowBackColor);
    ui ->mainTextEdit ->setPalette (palette);

    ConfigInfo info;
    info.Set_Inf(this ->fileName,
                 this ->setWindowsClarity,
                 this ->setMainTextSize,
                 this ->setMainTextBold,
                 this ->setMainTextItalic,
                 this ->setMainTextColorIndex,
                 this ->setMainWindowBackColorIndex);
    info.Open_File_Write ();
}

NoteBook::~NoteBook()
{
    delete ui;
    ui = NULL;
}
