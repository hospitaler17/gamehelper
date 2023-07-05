#ifndef SCALEDPIXMAP_H
#define SCALEDPIXMAP_H

#include <QtWidgets/QLabel>
#include <QtGui/QPixmap>
#include <QPainter>

QT_FORWARD_DECLARE_CLASS(QPaintEvent)

class ScaledPixmap : public QLabel
{
    Q_OBJECT
public:
    explicit ScaledPixmap(QWidget* parent = Q_NULLPTR);

    bool overscalingEnabled() const;
    bool keepAspectRatioEnabled() const;
    bool fillSquareEnabled() const;

public slots:
    void setScaledPixmap(const QPixmap& pixmap);
    void loadPixmapData(const QString& path);

    void enableOverscaling(bool enable = true);
    void enableKeepAspectRatio(bool enable = true);
    void enableFillSquare(bool enable = true);


protected:
    void paintEvent(QPaintEvent*);

private:
    bool fitToScreen(const QSize& screenSize);

private:
    QPixmap m_pixmap;

    bool m_overscalingEnabled;//Игнорировать исходный размер
    bool m_keepAspectRatioEnabled; // Сохранять пропорции
    bool m_fillSquare; // Всегда квадрат
    QSize m_originalSize;
};


#endif // SCALEDPIXMAP_H
