/**
 *  Copyright (C) 2015 3D Repo Ltd
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "repocomboboxeditor.h"

repo::gui::RepoComboBoxEditor::RepoComboBoxEditor(
        const std::list<std::string> &list,
        QWidget *parent)
    : QComboBox(parent)
    , list(list)
{
    std::list<std::string>::iterator it = this->list.begin();
    for (int i = 0; it != this->list.end(); ++it, ++i)
    {
        QColor color("red");
        insertItem(i, QString::fromStdString(*it));
        setItemData(i, color, Qt::DecorationRole);
    }
}

repo::gui::RepoComboBoxEditor::~RepoComboBoxEditor()
{

}

QColor repo::gui::RepoComboBoxEditor::color() const
{
   return qvariant_cast<QColor>(itemData(currentIndex(), Qt::DecorationRole));
}

void repo::gui::RepoComboBoxEditor::setColor(QColor color)
{
   setCurrentIndex(findData(color, int(Qt::DecorationRole)));
}

QWidget * repo::gui::RepoComboBoxEditor::createWidget(QWidget * parent) const
{
    return new RepoComboBoxEditor(list, parent);
}

QByteArray repo::gui::RepoComboBoxEditor::valuePropertyName() const
{
    return QByteArray();
}