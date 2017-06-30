/*
    Copyright (C) 2014  Intel Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "xfstkdldrpluginoptionsinterface.h"
#include "ui_xfstkdldrpluginoptionsinterface.h"

XfstkDldrPluginOptionsInterface::XfstkDldrPluginOptionsInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XfstkDldrPluginOptionsInterface)
{
    ui->setupUi(this);
}

XfstkDldrPluginOptionsInterface::~XfstkDldrPluginOptionsInterface()
{
    if(ui)
    {
        delete ui;
        ui = NULL;
    }
}

QTabWidget *XfstkDldrPluginOptionsInterface::GetTabInterface()
{
    return this->ui->OptionsInterface;
}

void XfstkDldrPluginOptionsInterface::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
