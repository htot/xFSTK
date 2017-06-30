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
#ifndef XFSTKDLDRTHREAD_H
#define XFSTKDLDRTHREAD_H

#include <QObject>
#include <QMutex>
#include <QSize>
#include <QThread>
#include <QWaitCondition>
#include <xfstkdldrapi.h>
#include <QMutexLocker>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <QStringList>
#include <QTime>
#include <QDir>
#include <QTextStream>

class xfstkdldrthreadobj : public QObject
{
Q_OBJECT
public:
    unsigned int isDebug;
    float time_elapsed;
    xfstkstatuspfn physstatuspfn;
    int retrycount;
    char *fwimage;
    int tid;
    int numtargets;
    bool provisioningok;
    explicit xfstkdldrthreadobj(QObject *parent = 0);
    void configuredownloader(char *fwimage, int tid, int numtargets, int retrycount);
    void go();
    bool bkill;
    bool bFwOnly;
    bool bLog;
    QString LogPath;

signals:
    void StatusUpdate(QString stuff);
    void ThreadComplete(bool result);
    void TargetsCompletedForThread(int numdone);
public slots:
private:
    bool downloadfwthread(char *fwimage);
};

class xfstkdldrthread : public QThread
{
Q_OBJECT
public:
    explicit xfstkdldrthread(QObject *parent = 0);
    ~xfstkdldrthread();
    xfstkdldrthreadobj *obj;
    void setobj(xfstkdldrthreadobj *obj);
signals:
    void done();

public slots:
protected:
    void run();

private:
    QMutex mutex;
    QWaitCondition condition;
};

#endif // XFSTKDLDRTHREAD_H