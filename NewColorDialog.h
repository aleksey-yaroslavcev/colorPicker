#ifndef NEWCOLORDIALOG_H
#define NEWCOLORDIALOG_H

#include <QDialog>
#include <QColor>

namespace Ui {
class NewColorDialog;
}

class NewColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewColorDialog(QWidget* parent = 0);
    ~NewColorDialog();

signals:
    void newColorSelected(QColor);

private:
    Ui::NewColorDialog* ui;

    // QDialog interface
public slots:
    virtual void accept() override;
    virtual void reject() override;
};

#endif // NEWCOLORDIALOG_H
