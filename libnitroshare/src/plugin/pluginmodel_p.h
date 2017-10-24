/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef LIBNITROSHARE_PLUGINMODEL_P_H
#define LIBNITROSHARE_PLUGINMODEL_P_H

#include <QHash>
#include <QList>
#include <QObject>

#include <nitroshare/pluginmodel.h>

class Application;
class Plugin;

class PluginModelPrivate : public QObject
{
    Q_OBJECT

public:

    PluginModelPrivate(PluginModel *model, Application *application);
    virtual ~PluginModelPrivate();

    void emitChangeSignal(Plugin *plugin);
    bool loadPlugin(Plugin *plugin);
    void unloadPlugin(Plugin *plugin);
    bool initializePlugin(Plugin *plugin);
    void cleanupPlugin(Plugin *plugin);

    PluginModel *const q;

    Application *application;
    QList<Plugin*> pluginList;
    QHash<QString, Plugin*> pluginHash;
    QStringList pluginBlacklist;
};

#endif // LIBNITROSHARE_PLUGINMODEL_P_H