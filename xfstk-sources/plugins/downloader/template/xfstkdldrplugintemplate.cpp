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
#include "xfstkdldrplugintemplate.h"

XfstkDldrPluginTemplate::XfstkDldrPluginTemplate()
{
    this->PluginInfo.PlatformName = QString("Template");
    this->PluginInfo.PluginName = QString("Template");
    this->PluginInfo.PluginInterface = (XfstkDldrPluginInterface *)this;
}

XfstkDldrPluginInterface* XfstkDldrPluginTemplate::Create()
{
    return new XfstkDldrPluginTemplate();
}

QTabWidget *XfstkDldrPluginTemplate::GetUserTabInterface()
{
    return this->UserTabInterface.GetTabInterface();
}

QTabWidget *XfstkDldrPluginTemplate::GetOptionsTabInterface()
{
    return this->OptionsTabInterface.GetTabInterface();
}

bool XfstkDldrPluginTemplate::InitializeTabInterfaces()
{
    return true;
}

bool XfstkDldrPluginTemplate::SaveTabInterfaceSettings()
{
    return true;
}

bool XfstkDldrPluginTemplate::RestoreTabInterfaceSettings()
{
    return true;
}

XfstkDldrPluginInfo *XfstkDldrPluginTemplate::GetPluginInfo()
{
    return &(this->PluginInfo);
}

bool XfstkDldrPluginTemplate::Init()
{
    return true;
}

Q_EXPORT_PLUGIN2(XfstkDldrPluginTemplate, XfstkDldrPluginTemplate)