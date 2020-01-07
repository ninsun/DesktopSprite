#include "Theme.h"
#include "Action.h"

Theme::Theme(QObject *parent)
    : QObject(parent)
{
}

Theme::~Theme()
{
}

void Theme::setCurrentAction(int val)
{
    if (val >= 0 && val < m_actionList.count())
    {
        m_currentAction = val;
    }
}

void Theme::nextAction()
{
    if (m_currentAction == m_actionList.count() - 1)
    {
        m_currentAction = 0;
    }
    else
    {
        ++m_currentAction;
    }
    auto _action = m_actionList.value(m_currentAction);
    _action->reset();
}

const QPixmap &Theme::getPixmap()
{
    auto _action = m_actionList.value(m_currentAction);
    if (_action)
    {
        return _action->getPixmap();
    }
    else
    {
        return QPixmap();
    }
}