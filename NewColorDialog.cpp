#include "NewColorDialog.h"
#include "ui_NewColorDialog.h"

NewColorDialog::NewColorDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::NewColorDialog)
{
    ui->setupUi(this);
}

NewColorDialog::~NewColorDialog()
{
    delete ui;
}

void NewColorDialog::accept()
{
    emit newColorSelected(QColor(ui->spinR->value(), ui->spinG->value(), ui->spinB->value()));
    QDialog::accept();
    deleteLater();
}

void NewColorDialog::reject()
{
    QDialog::reject();
    deleteLater();
}
