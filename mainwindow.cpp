#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#define HOME_PAGE 0
#define GAME_PAGE 1
#define MANAGE_ACCOUNTS_PAGE 2
#define UPDATE_ACCOUNT_PAGE 3
#define DIFFICULTY_PAGE 4
#define CREATE_ACCOUNT_PAGE 5
#define ACCOUNTS_PAGE 6
#define PLAYER_PAGE 7
#define ADMIN_PAGE 8

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(HOME_PAGE);
    ui->accountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->manageAccountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onButton3Cliecked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------- HOME PAGE ----------------
void MainWindow::on_playAsGuestButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(DIFFICULTY_PAGE);
}

// ---------------- ACCOUNTS PAGE ----------------
void MainWindow::on_loginAccountsButton_clicked()
{
    // zaloguj wybranego użytkownika
    // potem np. ui->stackedWidget->setCurrentIndex(PLAYER_PAGE); lub ADMIN_PAGE
}

void MainWindow::on_createAccountAccountsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(CREATE_ACCOUNT_PAGE);
}

// ---------------- CREATE ACCOUNT PAGE ----------------
void MainWindow::on_createAccountCreateAccountButton_clicked()
{
    // dodaj nowe konto do listy
}

void MainWindow::on_returnUpsertAccountButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ACCOUNTS_PAGE);
}

// ---------------- GAME PAGE ----------------
void MainWindow::on_cancelGameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(HOME_PAGE); // lub DIFFICULTY_PAGE, zależnie od kontekstu
}

void MainWindow::on_resetGameButton_clicked()
{
    // zresetuj planszę
}

void MainWindow::on_solutionGameButton_clicked()
{
    // pokaż rozwiązanie
}

void MainWindow::on_stepGameButton_clicked()
{
    // pokaż jeden ruch rozwiązania
}

void MainWindow::on_hintGameButton_clicked()
{
    // pokaż podpowiedź
}

void MainWindow::on_infoGameButton_clicked()
{
    QMessageBox::information(this, "Informacja", "Ułóż liczby od 1 do n.");
}

void MainWindow::on_pushButton_clicked()
{
    // zatrzymaj grę
}

// ---------------- PLAYER PAGE ----------------
void MainWindow::on_playAsPlayerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(DIFFICULTY_PAGE);
}

void MainWindow::on_showScoresButton_clicked()
{
    // pokaż wyniki
}

void MainWindow::on_retrunButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(HOME_PAGE);
}

// ---------------- ADMIN PAGE ----------------
void MainWindow::on_playAdminButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(DIFFICULTY_PAGE);
}

void MainWindow::on_showScoresAdminButton_clicked()
{
    // pokaż wyniki dla admina
}

void MainWindow::on_showAccountsAdminButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(MANAGE_ACCOUNTS_PAGE);
}

void MainWindow::on_returnAdminButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(HOME_PAGE);
}

// ---------------- MANAGE ACCOUNTS PAGE ----------------
void MainWindow::on_editManageAccountsButton_clicked()
{
    // edytuj wybrane konto i przejdź do UPDATE_ACCOUNT_PAGE
    ui->stackedWidget->setCurrentIndex(UPDATE_ACCOUNT_PAGE);
}

void MainWindow::on_deleteManageAccountsButton_clicked()
{
    // usuń wybrane konto
}

void MainWindow::on_returnManageAccountsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ADMIN_PAGE);
}

// ---------------- UPDATE ACCOUNT PAGE ----------------
void MainWindow::on_createAccountUpdateAccountButton_clicked()
{
    // zapisz zmiany konta
}

void MainWindow::on_returnUpdateAccountButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(MANAGE_ACCOUNTS_PAGE);
}

// ---------------- DIFFICULTY PAGE ----------------
void MainWindow::on_easyDifficultyButton_clicked()
{
    // przygotuj planszę np. 3x3
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
}

void MainWindow::on_normalDifficultyButton_clicked()
{
    // przygotuj planszę np. 4x4
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
}

void MainWindow::on_hardDifficultyButton_clicked()
{
    // przygotuj planszę np. 5x5
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
}

void MainWindow::on_customDifficultyButton_clicked()
{
    int value = ui->customDifficultySpin->value();
    // przygotuj planszę nxn, gdzie n = value
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
}

void MainWindow::on_returnDifficultyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(HOME_PAGE); // lub PLAYER_PAGE/ADMIN_PAGE zależnie od ścieżki
}
