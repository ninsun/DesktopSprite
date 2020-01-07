#pragma once

#include <QObject>

class Action;
class Theme : public QObject
{
    Q_OBJECT

public:
    Theme(QObject *parent = nullptr);
    ~Theme();
    void addAction(Action *action) { m_actionList << action; }
    void removeAction(Action *action) { m_actionList.removeAll(action); }
    const QList<Action *> &actionList() { return m_actionList; }
    void setCurrentAction(int val);
    void nextAction();
    const QPixmap &getPixmap();
private:
    QList<Action *> m_actionList;
    int m_currentAction = 0;
};
