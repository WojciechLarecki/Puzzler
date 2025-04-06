#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->
    ui->accountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->manageAccountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onButton3Cliecked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --------EVENTS---------
void MainWindow::onButton3Cliecked() {
//     //auto isVisible = ui->pushButton_3->isVisible();
//     //ui->pushButton_3->setVisible(!isVisible);
//     //QMessageBox::information(this, "Clicked", "push_button3 was clicked!");
//     //ui->stackedWidget->setCurrentIndex(1);
}
