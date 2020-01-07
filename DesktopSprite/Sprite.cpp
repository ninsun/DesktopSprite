#include "Sprite.h"
#include <QPainter>
#include <QBrush>
#include <QApplication>
#include <QMouseEvent>
#include "Action.h"

Sprite::Sprite(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    initMenu();

    initDefaultTheme();

    startTimer(50);
}

Sprite::~Sprite()
{
}

void Sprite::paintEvent(QPaintEvent *event)
{
    resize(128 + 2, 128 + 2);
    QPainter _p(this);
    _p.setRenderHint(QPainter::Antialiasing);
    _p.setRenderHint(QPainter::HighQualityAntialiasing);
    _p.drawPixmap(1, 1, m_defaultTheme.getPixmap());
}

void Sprite::mousePressEvent(QMouseEvent *event)
{
    m_pos = event->globalPos();
    m_geometry = geometry();
    if (event->button() == Qt::RightButton)
    {
        m_menu.popup(m_pos);
    }
}

void Sprite::mouseMoveEvent(QMouseEvent *event)
{
    QRect _geometry = m_geometry;
    _geometry.moveTopLeft(event->globalPos() - m_pos + m_geometry.topLeft());
    setGeometry(_geometry);
}

void Sprite::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_defaultTheme.nextAction();
}

void Sprite::timerEvent(QTimerEvent *event)
{
    repaint();
}

void Sprite::initMenu()
{
    m_menu.addAction(QStringLiteral("ÉèÖÃ"), [&]() {
        m_setting.show();
    });
    m_menu.addAction(QStringLiteral("ÍË³ö"), []() {
        qApp->quit();
    });
}

void Sprite::initDefaultTheme()
{
    Action *_defaultAction = nullptr;

    _defaultAction = new Action();
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Awake.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Idle.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Sleep.png");
    _defaultAction->setDelay(10000);
    _defaultAction->start();
    m_defaultTheme.addAction(_defaultAction);

    _defaultAction = new Action();
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Alert1.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Alert2.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Alert3.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Alert4.png");
    _defaultAction->setMode(Action::symmetry);
    _defaultAction->start();
    m_defaultTheme.addAction(_defaultAction);

    _defaultAction = new Action();
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting1.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting2.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting3.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting4.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting5.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting6.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting7.png");
    _defaultAction->addPixmap(":/DesktopSprite/Resources/Connecting8.png");
    _defaultAction->start();
    m_defaultTheme.addAction(_defaultAction);
}