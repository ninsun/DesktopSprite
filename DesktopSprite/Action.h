#pragma once

#include <QObject>
#include <QList>
#include <QMap>
#include <QPixmap>

class Action : public QObject
{
    Q_OBJECT
public:
    enum Mode
    {
        loop,
        symmetry,
    };
public:
    Action(QObject *parent = nullptr);
    ~Action();
public:
    void reset();
    void addPixmap(const QString &fileName);
    void setOrder(const QList<int> &order) { m_order = order; }
    void setDelay(int delay) { m_delay = delay; start(); }
    int delay() { return m_delay; }
    void setMode(Mode mode);
    Mode mode() { return m_mode; }
    void start();
    void stop();
    const QPixmap &getPixmap() { return m_pixmapMap.value(m_order.value(m_currentIndex)); }
protected:
    void timerEvent(QTimerEvent *event);
private:
    int m_timerID = -1;
    int m_delay = 50;
    Mode m_mode = loop;
    int m_currentIndex = 0;
    int m_add = 1;
    QMap<int, QPixmap> m_pixmapMap;
    QList<int> m_order;
};
