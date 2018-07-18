#ifndef NEWCOLORDIALOG_H
#define NEWCOLORDIALOG_H

#include <QDialog>

namespace Ui {
class NewColorDialog;
}

class NewColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewColorDialog(QWidget *parent = 0);
    ~NewColorDialog();

private:
    Ui::NewColorDialog *ui;
};

#endif // NEWCOLORDIALOG_H
