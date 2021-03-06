#pragma once

#include <QApplication>
#include <QColor>
#include <QFont>

class GraphicsSettings
{
public:
    static GraphicsSettings *instance();
    ~GraphicsSettings();


    void setPenWidth(int width);
    void setIsDrawing(bool isDrawing);
    void setFont(QFont);
    void setColor(QColor color);
    void setRatio(qreal xRatio, qreal yRatio);

    inline const QColor& getPenColor(){return penColor;}
    inline int getPenWidth(){return penWidth;}
    inline bool getIsDrawingFlag(){return isDrawingFlag;}
    inline QFont getFont() {return penFont;}
    inline qreal getXRatio() {return imageXRatio;}
    inline qreal getYRatio() {return imageYRatio;}

protected:
    GraphicsSettings();

private:
    int penWidth;
    bool isDrawingFlag;
    QFont penFont;
    QColor penColor;

    qreal imageXRatio, imageYRatio;

    // 用于存储第一段图应有的高度和宽度
    // 用于校正每张图片的高度
    qint32 imageHeight, imageWidth;

    static GraphicsSettings* GraphicsSettingInstance;
};
