#pragma once

#include <QWidget>
#include <QPicture>
#include <QMenu>
#include "Setting.h"
#include "Theme.h"
class Sprite : public QWidget
{
    Q_OBJECT

public:
    Sprite(QWidget *parent = nullptr);
    ~Sprite();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
private:
    void initMenu();
    void initDefaultTheme();
private:
    Theme m_defaultTheme;
    QPoint m_pos;
    QRect m_geometry;
    QMenu m_menu;
    Setting m_setting;
};
