#include "imagewidget.h"
#include <QDebug>
#include <QPainter>
#include <QResizeEvent>

ImageWidget::ImageWidget(QWidget *parent)
    : QLabel(parent), m_rows(0), m_cols(0) {
  setFrameShape(QFrame::Box);
  setAlignment(Qt::AlignCenter);
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(true);
    setSizePolicy(sizePolicy);

    setScaledContents(true);
    setMinimumSize(1, 1);

    setFrameShape(QFrame::Box);
}

void ImageWidget::setImage(const QPixmap &image) {
  m_pixmap = image;

  m_cols = m_pixmap.width();
  m_rows = m_pixmap.height();

  updatePixmap();
}

/* virtual */ QSize ImageWidget::sizeHint() const { return m_square.size(); }

/* virtual */ void ImageWidget::resizeEvent(QResizeEvent *e) {
  QLabel::resizeEvent(e);
  updatePixmap();


QPixmap ImageWidget::scaledPixmap()
{
    qDebug() << "Label size: "  << this->size();
    QPixmap pix = m_pixmap.scaled(width(), heightForWidth(width()), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    qDebug() << "Scaled image size: " << pix.size();

    return pix;
}

void ImageWidget::updatePixmap() {

  static constexpr int margin =
      10; // space between the outer frame (our border) and the actual square
          // image (the blue background currently)
  const int side = qMin(width(), height()) - margin;

  m_square = QPixmap(side, side);
  m_square.fill(Qt::blue);

  if (!m_pixmap.isNull()) {
    QPainter p(&m_square);
    const QPixmap scaled = m_pixmap.scaled(m_square.size(), Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation);
    const QRect &scaledRect = scaled.rect();
    const QRect &bgrRect = m_square.rect();

    // draw the scaled image in the center of the square:
    p.drawPixmap((bgrRect.width() - scaledRect.width()) / 2,
                 (bgrRect.height() - scaledRect.height()) / 2, scaled);
  }

  setPixmap(m_square);
}



void ImageWidget::updateImage()
{
    if(!m_pixmap.isNull())
    {
        QLabel::setPixmap(scaledPixmap());
    }
}
