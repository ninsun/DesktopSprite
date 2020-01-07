#include "Action.h"

Action::Action(QObject *parent)
    : QObject(parent)
{
}

Action::~Action()
{
}

void Action::reset()
{
    m_currentIndex = 0;
    m_add = 1;
}

void Action::addPixmap(const QString &fileName)
{
    int _index = m_pixmapMap.count();
    m_pixmapMap.insert(_index, QPixmap(fileName));
    m_order << _index;
}

void Action::setMode(Mode mode)
{
    m_currentIndex = 0;
    m_add = 1;
    m_mode = mode;
}

void Action::start()
{
    if (m_timerID != -1)
    {
        stop();
    }
    m_timerID = startTimer(m_delay);
}

void Action::stop()
{
    killTimer(m_timerID);
    m_timerID = -1;
}

void Action::timerEvent(QTimerEvent *event)
{
    if (m_currentIndex == m_order.count() - 1)
    {
        if (m_mode == symmetry)
        {
            m_add = -1;
        }
        else if (m_mode == loop)
        {
            m_add = 1;
            m_currentIndex = -1;
        }
    }
    else if (m_currentIndex == 0)
    {
        m_add = 1;
    }
    m_currentIndex += m_add;
}