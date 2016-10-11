#include "setting.h"
#include "notebook.h"

Setting::Setting(QWidget *parent) : QDialog(parent), ui(new Ui::Setting)
{
    ui->setupUi(this);
    Init_Set();
    Init_Connection();
    InIt_Setting();
}

void Setting::Init_Connection()
{
    connect (ui ->setModify, &QPushButton::clicked , this, &Setting::settingApplyActionClicked);
    connect (ui ->setOk, &QPushButton::clicked , this, &Setting::settingOkActionClicked);
    connect (ui ->setWindowsClaritySlider, &QSlider::valueChanged , this, &Setting::setWindowsClarityLabel_Slot);
    connect (ui ->OpenFile, &QPushButton::clicked, this ,&Setting::settingOpenFileActionClicked_Slot);

}

void Setting::Init_Set()
{
    //setMainTextFont
    setWindowsClarity = 20;       //窗口透明度；
    setMainTextSize = 40;               //设置字体大小；
    setMainTextBold = false;       //设置字体加粗；
    setMainTextItalic = false;         //设置字体倾斜；
    setMainTextColor = 1;
    setMainWindowBackColor = 1;

    ui ->setWindowsClaritySlider ->setMinimum (6);
    ui ->setWindowsClaritySlider ->setMaximum (100);
    ui ->setWindowsClaritySlider ->setTickInterval (1);
    ui ->setWindowsClaritySlider ->setSliderPosition (100);
    ui ->setWindowsClarityLabel ->setText(QString::number (100));

    setFontSizeComboBox();
    setFontColorComboBox();
    setWindowBackColorComboBox();
}

void Setting::InIt_Setting()
{
    ui ->setWindowsClarityLabel ->setText (QString::number (setWindowsClarity));
    ui ->setWindowsClaritySlider ->setSliderPosition (setWindowsClarity);
    ui ->setFontSizeComboBox ->setCurrentIndex (setMainTextSize - 6);
    ui ->setFontColorComboBox ->setCurrentIndex (setMainTextColor);
    ui ->setBackGroundColorComboBox ->setCurrentIndex (setMainWindowBackColor);
}

void Setting::setFontSizeComboBox()
{
    //QStringList longerList = (QStringList() << str1 << str2 << str3);
    ui ->setFontSizeComboBox->addItems (QStringList()
                                        <<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"
                                        <<"16"<<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24"<<"25"
                                        <<"26"<<"27"<<"28"<<"29"<<"30"<<"31"<<"32"<<"33"<<"34"<<"35"
                                        <<"36"<<"37"<<"38"<<"39"<<"40"<<"41"<<"42"<<"43"<<"44"<<"45"
                                        <<"46"<<"47"<<"48"<<"49"<<"50"<<"51"<<"52"<<"53"<<"54"<<"55"
                                        <<"56"<<"57"<<"58"<<"59"<<"60"<<"61"<<"62"<<"63"<<"64"<<"65"
                                        <<"66"<<"67"<<"68"<<"69"<<"70"<<"71"<<"72"<<"73"<<"74"<<"75"
                                        <<"76"<<"77"<<"78"<<"79"<<"80"<<"81"<<"82"<<"83"<<"84"<<"85");
}

void Setting::setFontColorComboBox()
{
    ui ->setFontColorComboBox ->addItems (QStringList() <<tr("白色")<<tr("粉红")
                                          <<tr("猩红")<<tr("脸红的淡紫色")<<tr("苍白的紫罗兰红色")
                                          <<tr("热情的粉红")<<tr("深粉色")<<tr("适中的紫罗兰红色")
                                          <<tr("兰花的紫色")<<tr("蓟") <<tr("李子")<<tr("紫罗兰")
                                          <<tr("洋红")<<tr("紫红色")<<tr("深洋红色")<<tr("紫色")
                                          <<tr("适中的兰花紫")<<tr("深紫罗兰色")<<tr("深兰花紫")
                                          <<tr("靛青")<<tr("深紫罗兰的蓝色")<<tr("适中的紫色")
                                          <<tr("适中的板岩暗蓝灰色")<<tr("板岩暗蓝灰色")
                                          <<tr("深岩暗蓝灰色")<<tr("熏衣草花的淡紫色")<<tr("幽灵的白色")
                                          <<tr("纯蓝")<<tr("适中的蓝色")<<tr("午夜的蓝色")<<tr("深蓝色")
                                          <<tr("海军蓝")<<tr("皇军蓝")<<tr("矢车菊的蓝色")<<tr("淡钢蓝")
                                          <<tr("浅石板灰")<<tr("石板灰")<<tr("道奇蓝") <<tr("爱丽丝蓝")
                                          <<tr("淡蓝色")<<tr("深天蓝")<<tr("青色")<<tr("适中的春天的绿色")
                                          <<tr("薄荷奶油")<<tr("春天的绿色")<<tr("酸橙色")<<tr("象牙")
                                          <<tr("浅黄色")<<tr("灰秋麒麟")<<tr("橙色")<<tr("鹿皮鞋")
                                          <<tr("浅鲜肉(鲑鱼)色") <<tr("橙红色")<<tr("鲜肉(鲑鱼)色")
                                          <<tr("纯红")<<tr("黑色"));

}

void Setting::setWindowBackColorComboBox()
{
    ui ->setBackGroundColorComboBox ->addItems (QStringList() <<tr("白色")<<tr("粉红")
                                          <<tr("猩红")<<tr("脸红的淡紫色")<<tr("苍白的紫罗兰红色")
                                          <<tr("热情的粉红")<<tr("深粉色")<<tr("适中的紫罗兰红色")
                                          <<tr("兰花的紫色")<<tr("蓟") <<tr("李子")<<tr("紫罗兰")
                                          <<tr("洋红")<<tr("紫红色")<<tr("深洋红色")<<tr("紫色")
                                          <<tr("适中的兰花紫")<<tr("深紫罗兰色")<<tr("深兰花紫")
                                          <<tr("靛青")<<tr("深紫罗兰的蓝色")<<tr("适中的紫色")
                                          <<tr("适中的板岩暗蓝灰色")<<tr("板岩暗蓝灰色")
                                          <<tr("深岩暗蓝灰色")<<tr("熏衣草花的淡紫色")<<tr("幽灵的白色")
                                          <<tr("纯蓝")<<tr("适中的蓝色")<<tr("午夜的蓝色")<<tr("深蓝色")
                                          <<tr("海军蓝")<<tr("皇军蓝")<<tr("矢车菊的蓝色")<<tr("淡钢蓝")
                                          <<tr("浅石板灰")<<tr("石板灰")<<tr("道奇蓝") <<tr("爱丽丝蓝")
                                          <<tr("淡蓝色")<<tr("深天蓝")<<tr("青色")<<tr("适中的春天的绿色")
                                          <<tr("薄荷奶油")<<tr("春天的绿色")<<tr("酸橙色")<<tr("象牙")
                                          <<tr("浅黄色")<<tr("灰秋麒麟")<<tr("橙色")<<tr("鹿皮鞋")
                                          <<tr("浅鲜肉(鲑鱼)色") <<tr("橙红色")<<tr("鲜肉(鲑鱼)色")
                                          <<tr("纯红")<<tr("黑色"));

}

void Setting::setWindowsClarityLabel_Slot(int value)
{
    ui ->setWindowsClarityLabel->setText (QString::number (value));
}

void Setting::settingApplyActionClicked()
{
    this ->fileName = ui ->DefaultPath ->text ();
    this ->setWindowsClarity = ui ->setWindowsClarityLabel ->text ().toInt ();
    this ->setMainTextFont = ui ->setFontComboBox ->currentFont ();
    this ->setMainTextSize = ui ->setFontSizeComboBox ->currentText ().toInt ();
    this ->setMainTextBold = ui ->setFontBold ->isChecked ();
    this ->setMainTextItalic = ui ->setFontItalic ->isChecked ();
    this ->setMainTextColor = ui ->setFontColorComboBox ->currentIndex ();
    this ->setMainWindowBackColor = ui ->setBackGroundColorComboBox ->currentIndex ();

    emit freshNewSetting(fileName ,setWindowsClarity , setMainTextFont, setMainTextSize , setMainTextBold, setMainTextItalic, setMainTextColor, setMainWindowBackColor);
}

void Setting::settingOkActionClicked()
{
    this ->settingApplyActionClicked ();
    this ->close ();
}

void Setting::settingOpenFileActionClicked_Slot()
{
    QString tmp;
    QFileDialog::Options option;
    option = QFileDialog::ReadOnly | QFileDialog::DontResolveSymlinks;
    tmp = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/",option);
    ui ->DefaultPath ->setText (tmp);
    fileName = tmp;
}

Setting::~Setting()
{
    delete ui;
}

