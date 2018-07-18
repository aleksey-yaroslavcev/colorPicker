#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QList>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void onNewColorSelected(QColor color);

private slots:
    void on_actionAddColor_triggered();
    void on_actionRemoveLastColor_triggered();

    void on_actionSaveToFile_triggered();
    void on_actionLoadFromFile_triggered();

private:
    Ui::MainWindow* ui;
    QList<QColor> _colors;
    QList <QPushButton*> _buttons;
};

#endif // MAINWINDOW_H
