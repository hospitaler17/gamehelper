#include "scaledpixmap.h"

ScaledPixmap::ScaledPixmap(QWidget *parent)
    : QLabel(parent)
    , m_overscalingEnabled(true)
    , m_keepAspectRatioEnabled(true)
    , m_fillSquare(true)
{

}

bool ScaledPixmap::overscalingEnabled() const
{
    return m_overscalingEnabled;
}

bool ScaledPixmap::keepAspectRatioEnabled() const
{
    return m_keepAspectRatioEnabled;
}

bool ScaledPixmap::fillSquareEnabled() const
{
    return m_fillSquare;
}

void ScaledPixmap::setScaledPixmap(const QPixmap &pixmap)
{
    m_pixmap = pixmap;
    m_originalSize = pixmap.size();
    update();
}

void ScaledPixmap::loadPixmapData(const QString &path)
{
    QPixmap pixmap(path);

    const bool loader = pixmap.isNull();

    if(loader)
        setScaledPixmap(pixmap);
}

void ScaledPixmap::enableOverscaling(bool enable)
{
    m_overscalingEnabled = enable;
    update();
}

void ScaledPixmap::enableKeepAspectRatio(bool enable)
{
    m_keepAspectRatioEnabled = enable;
    update();
}

void ScaledPixmap::enableFillSquare(bool enable)
{
    m_fillSquare = enable;
    update();
}

bool ScaledPixmap::fitToScreen(const QSize& screenSize)
{
    return (screenSize.width()>=m_originalSize.width() && (screenSize.height()>=m_originalSize.height()));
}

void ScaledPixmap::paintEvent(QPaintEvent * const event)
{
    QPainter painter(this);



    if(!m_pixmap.isNull())
    {
        QPoint centerPoint (0,0);
        if(!m_fillSquare)
        {

            QSize scaledSize = overscalingEnabled() ? size() : (fitToScreen(size()) ? m_originalSize : size());
            QPixmap scaledPixmap = m_pixmap.scaled(scaledSize, m_keepAspectRatioEnabled ? Qt::KeepAspectRatio : Qt::IgnoreAspectRatio);

            centerPoint.setX((size().width()-scaledPixmap.width())/2);
            centerPoint.setY((size().height()-scaledPixmap.height())/2);

            painter.drawPixmap(centerPoint,scaledPixmap);
        }
        else {
            QSize scaledSize = overscalingEnabled() ? size() : (fitToScreen(size()) ? m_originalSize : size());

            int sMin = scaledSize.width()<scaledSize.height() ? scaledSize.width() : scaledSize.height();

            QSize sizeMin(sMin,sMin);
            QPixmap scaledPixmap = m_pixmap.scaled(sizeMin,  Qt::IgnoreAspectRatio);

            centerPoint.setX((size().width()-scaledPixmap.width())/2);
            centerPoint.setY((size().height()-scaledPixmap.height())/2);

            painter.drawPixmap(centerPoint,scaledPixmap);

        }

    }

    QLabel::paintEvent(event);
}


