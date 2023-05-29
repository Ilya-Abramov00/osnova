#ifndef SPECTR_H
#define SPECTR_H

#include <QDialog>
#include <math.h>

namespace Ui {
class Spectr;
}

class Spectr : public QDialog
{
    Q_OBJECT

public:
    explicit Spectr(QWidget *parent = nullptr);
    ~Spectr();

private:
    Ui::Spectr *ui;

public slots:
    void slot (QVector<double>& x_t  , QVector<double>& y_t_re , QVector<double>& y_t_im  );

};

#endif // SPECTR_H
