/**
Released as open source by Gabriel Caudrelier

Developed by Gabriel Caudrelier, gabriel dot caudrelier at gmail dot com

https://github.com/metrodango/pip3line

Released under AGPL see LICENSE for more information
**/

#include "singleviewabstract.h"
#include "../loggerwidget.h"
#include "../guihelper.h"
#include "../sources/bytesourceabstract.h"
#include <transformabstract.h>
#include <transformmgmt.h>
#include <threadedprocessor.h>

SingleViewAbstract::SingleViewAbstract(ByteSourceAbstract *dataModel,GuiHelper *nguiHelper, QWidget *parent, bool takeByteSourceOwnership) :
    QWidget(parent),
    hasSourceOwnership(takeByteSourceOwnership)
{
    byteSource = dataModel;
    guiHelper = nguiHelper;
    logger = guiHelper->getLogger();
    configButton = nullptr;
}

SingleViewAbstract::~SingleViewAbstract()
{
    if (hasSourceOwnership) {
        delete byteSource;
    }
    byteSource = nullptr;
    logger = nullptr;
}

void SingleViewAbstract::searchAgain()
{
    return search(previousSearch,previousMask);
}

QPushButton *SingleViewAbstract::getConfigButton() const
{
    return configButton;
}

void SingleViewAbstract::setConfigButton(QPushButton *value)
{
    configButton = value;
}

QHash<QString, QString> SingleViewAbstract::getConfiguration()
{
    QHash<QString, QString> conf;
    // nothing to see here
    return conf;
}

void SingleViewAbstract::setConfiguration(QHash<QString, QString> /*conf*/)
{
    // nothing to restore ... yet
}

ByteSourceAbstract *SingleViewAbstract::getByteSource() const
{
    return byteSource;
}

