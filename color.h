#ifndef COLOR_H
#define COLOR_H
#include <QColor>

class Color
{
public:
    Color();
private:
    friend class Setting;
    friend class NoteBook;
private:
    QColor White();
    QColor Pink();//
    QColor Crimson();//
    QColor LavenderBlush();//
    QColor PaleVioletRed();//
    QColor HotPink();//
    QColor DeepPink();//
    QColor MediumVioletRed();//
    QColor Orchid();//
    QColor Thistle();//
    QColor plum();//
    QColor Violet();//
    QColor Magenta();//
    QColor Fuchsia();//
    QColor DarkMagenta();//
    QColor Purple();//
    QColor MediumOrchid();//
    QColor DarkVoilet();//
    QColor DarkOrchid();//
    QColor Indigo();//
    QColor BlueViolet();
    QColor MediumPurple();
    QColor MediumSlateBlue();
    QColor SlateBlue();
    QColor DarkSlateBlue();
    QColor Lavender();
    QColor GhostWhite();
    QColor Blue();
    QColor MediumBlue();
    QColor MidnightBlue();
    QColor DarkBlue();
    QColor Navy();
    QColor RoyalBlue();
    QColor CornflowerBlue();
    QColor LightSteelBlue();
    QColor LightSlateGray();
    QColor DoderBlue();
    QColor AliceBlue();
    QColor LightSkyBlue();
    QColor DeepSkyBlue();
    QColor Cyan();
    QColor MediumSpringGreen();
    QColor MintCream();
    QColor SpringGreen();
    QColor Lime();
    QColor Ivory();
    QColor LightYellow();
    QColor PaleGodenrod();
    QColor Orange();
    QColor Moccasin();
    QColor LightSalmon();
    QColor OrangeRed();
    QColor Salmon();
    QColor Red();
    QColor Black();
};

#endif // COLOR_H
