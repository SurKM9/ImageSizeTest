#include "imagewidget.h"
#include <QDebug>

ImageWidget::ImageWidget(QWidget* parent) :
    QLabel(parent),
    m_rows(0),
    m_cols(0)
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(true);
    setSizePolicy(sizePolicy);

    setFrameShape(QFrame::Box);
}


void ImageWidget::setImage(const QPixmap& image)
{
    m_pixmap = image;

    m_cols = m_pixmap.width();
    m_rows = m_pixmap.height();

    QLabel::setPixmap(scaledPixmap());
}



QPixmap ImageWidget::scaledPixmap()
{
    return m_pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}



/* virtual */ QSize ImageWidget::sizeHint() const
{
    return QSize(m_cols, heightForWidth(m_cols));
}



/* virtual */ int ImageWidget::heightForWidth(int width) const
{
    return (m_cols != 0) ? width * m_rows / m_cols : width;
}