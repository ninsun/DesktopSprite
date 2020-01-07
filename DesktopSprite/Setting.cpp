#include "Setting.h"
#include <QMenu>
#include <QInputDialog>

Setting::Setting(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

Setting::~Setting()
{
}

void Setting::on_theme_customContextMenuRequested(const QPoint &pos)
{
    QMenu _menu;
    _menu.addAction(QStringLiteral("���"), [&]() {
        addTheme();
    });
    auto _item = ui.theme->itemAt(pos);
    if (_item)
    {
        _menu.addAction(QStringLiteral("ɾ��"), [&]() {
            removeTheme(_item);
        });
    }
    _menu.exec(QCursor::pos());
}

void Setting::on_action_customContextMenuRequested(const QPoint &pos)
{
}

void Setting::on_sequence_customContextMenuRequested(const QPoint &pos)
{
}

void Setting::addTheme()
{
    auto _name = QInputDialog::getText(this, QStringLiteral("�������"), QStringLiteral("������"));
    if (!_name.isEmpty())
    {
        ui.theme->addItem(_name);
    }
}

void Setting::removeTheme(QListWidgetItem *item)
{
    if (item)
        delete item;
}