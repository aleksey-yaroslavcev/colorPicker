#include "NewColorDialog.h"
#include "ui_NewColorDialog.h"

NewColorDialog::NewColorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewColorDialog)
{
    ui->setupUi(this);
}

NewColorDialog::~NewColorDialog()
{
    delete ui;
}
