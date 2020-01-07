#pragma once

#include <QWidget>
#include "ui_Setting.h"

class Setting : public QWidget
{
    Q_OBJECT

public:
    Setting(QWidget *parent = Q_NULLPTR);
    ~Setting();
private slots:
    void on_theme_customContextMenuRequested(const QPoint &pos);
    void on_action_customContextMenuRequested(const QPoint &pos);
    void on_sequence_customContextMenuRequested(const QPoint &pos);
private:
    void addTheme();
    void removeTheme(QListWidgetItem *item);
private:
    Ui::Setting ui;
};
