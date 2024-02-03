#include "mainwindow.h"
#include "mouseaction.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Create a click action
    MouseClickData clickData(QPoint(100, 100));

    // Cast MouseClickData to MouseActionData
    MouseActionData& baseClickData = clickData;

    // Invoke the MouseAction with the click data
    MouseAction mouseAction;
    mouseAction.Invoke(baseClickData);

}

