#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QLabel>
#include <QPixmap>



class ImageWidget : public QLabel {
public:
  ImageWidget(QWidget *parent = nullptr);

  /**
   * @brief Updates the image.
   * @param QImage
   */
  void setImage(const QPixmap &image);

  /**
   * @brief
   * Returns the recommended size for this widget.
   */
  virtual QSize sizeHint() const override;

  virtual void resizeEvent(QResizeEvent *e) override;

private:
  void updatePixmap();

  /**
   * @brief Property holding the image
   */
  QPixmap m_pixmap, m_square;

  /**
   * @brief This property holds the number of rows.
   */
  int m_rows;

  /**
   * This property holds the number of columns.
   */
  int m_cols;

class ImageWidget : public QLabel
{
    public:

        ImageWidget(QWidget* parent = nullptr);

        /**
         * @brief Updates the image.
         * @param image
         */
        void setImage(const QPixmap& image);

        /**
         * @brief
         * Returns the recommended size for this widget.
         */
        virtual QSize sizeHint() const override;

        /**
         * @brief Overwrite height for width
         * @param width
         * @return height
         */
        virtual int heightForWidth(int width) const override;

        void updateImage();

    private:

        QPixmap scaledPixmap();

        /**
         * @brief Property holding the image
         */
        QPixmap m_pixmap;

        /**
         * @brief This property holds the number of rows.
         */
        int m_rows;

        /**
         * This property holds the number of columns.
         */
        int m_cols;
};
#endif // IMAGEWIDGET_H
