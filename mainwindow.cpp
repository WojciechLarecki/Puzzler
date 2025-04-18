#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "./Controllers/databasecontroller.h"
#include "./Controllers/usercontroller.h"

#define HOME_PAGE 0
#define GAME_RESULTS_PAGE 1
#define GAME_PAGE 2
#define MANAGE_ACCOUNTS_PAGE 3
#define UPDATE_ACCOUNT_PAGE 4
#define DIFFICULTY_PAGE 5
#define CREATE_ACCOUNT_PAGE 6
#define ACCOUNTS_PAGE 7
#define PLAYER_PAGE 8
#define ADMIN_PAGE 9

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(HOME_PAGE);
    ui->accountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->manageAccountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->accountsTableWidget->setColumnHidden(0, true); // hide Id column
    ui->accountsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->accountsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->accountsTableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onAccountRowSelected);


    connect(ui->accountNameAccountCreateLineEdit, &QLineEdit::textChanged, this, &MainWindow::validateCreateAccountForm);
    connect(ui->playerRoleRadioButton, &QRadioButton::toggled, this, &MainWindow::validateCreateAccountForm);
    connect(ui->adminRoleRadioButton, &QRadioButton::toggled, this, &MainWindow::validateCreateAccountForm);
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onButton3Cliecked);

    connect(ui->returnGameResultsButton, &QPushButton::clicked, this, &MainWindow::goBack);

    try {
        DatabaseController db;
        db.Initialize();
    } catch (const std::exception& e) {
        ui->loginButton->setEnabled(false);
        QMessageBox::warning(this, "Wystąpił błąd.", "Program nie mógł wczytać bazy danych. Cześć funkcji będzie ograniczona");
    }

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

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_loginButton_clicked()
{
    resetAccountsPageState();
    ui->stackedWidget->setCurrentIndex(ACCOUNTS_PAGE);
}

// ---------------- ACCOUNTS PAGE ----------------
void MainWindow::on_loginAccountsButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->accountsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano żadnego użytkownika.");
        return;
    }

    int selectedRow = ui->accountsTableWidget->currentRow();
    QTableWidgetItem* roleItem = ui->accountsTableWidget->item(selectedRow, 1); // id (0), role (1), name (2)

    if (!roleItem) {
        QMessageBox::critical(this, "Błąd", "Nie udało się odczytać roli użytkownika.");
        return;
    }

    QString roleText = roleItem->text();

    if (roleText == "Gracz") {
        jumpTo(PLAYER_PAGE);
    } else if (roleText == "Admin") {
        jumpTo(ADMIN_PAGE);
    } else {
        QMessageBox::warning(this, "Błąd", "Nieznana rola użytkownika.");
    }
}

void MainWindow::on_createAccountAccountsButton_clicked()
{
    jumpTo(CREATE_ACCOUNT_PAGE);
}

void MainWindow::on_returnAccountsButton_clicked()
{
    goBack();
}

// ---------------- CREATE ACCOUNT PAGE ----------------
void MainWindow::on_createAccountCreateAccountButton_clicked()
{
    User user;
    user.setName(ui->accountNameAccountCreateLineEdit->text());
    if (ui->playerRoleRadioButton->isChecked())
        user.setRole(0);
    else user.setRole(1);

    UserController controller;
    controller.AddUser(user);

    refreshAccountsTable();
    jumpTo(ACCOUNTS_PAGE);
}

void MainWindow::on_returnUpsertAccountButton_clicked()
{
    refreshAccountsTable();
    goBack();
}

// ---------------- GAME PAGE ----------------
void MainWindow::on_cancelGameButton_clicked()
{
    jumpTo(HOME_PAGE); // lub DIFFICULTY_PAGE, zależnie od kontekstu
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
    jumpTo(DIFFICULTY_PAGE);
}

void MainWindow::on_showScoresButton_clicked()
{
    ui->deleteGameResultsButton->setVisible(false);
    jumpTo(GAME_RESULTS_PAGE);
}

void MainWindow::on_retrunButton_clicked()
{
    goBack();
}

// ---------------- ADMIN PAGE ----------------
void MainWindow::on_playAdminButton_clicked()
{
    jumpTo(DIFFICULTY_PAGE);
}

void MainWindow::on_showScoresAdminButton_clicked()
{
    jumpTo(GAME_RESULTS_PAGE);
}

void MainWindow::on_showAccountsAdminButton_clicked()
{
    ui->deleteGameResultsButton->setVisible(true);
    jumpTo(MANAGE_ACCOUNTS_PAGE);
}

void MainWindow::on_returnAdminButton_clicked()
{
    goBack();
}

// ---------------- MANAGE ACCOUNTS PAGE ----------------
void MainWindow::on_editManageAccountsButton_clicked()
{
    // edytuj wybrane konto i przejdź do UPDATE_ACCOUNT_PAGE
    jumpTo(UPDATE_ACCOUNT_PAGE);
}

void MainWindow::on_deleteManageAccountsButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->accountsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano żadnego użytkownika.");
        return;
    }

    int selectedRow = ui->accountsTableWidget->currentRow();
    QTableWidgetItem* userIdItem = ui->accountsTableWidget->item(selectedRow, 0);

    if (!userIdItem) {
        QMessageBox::critical(this, "Błąd", "Nie udało się wyniku gry.");
        return;
    }

    int userId = userIdItem->text().toInt();

    // TODO dorobić usuwanie konta
    UserController userController;
    userController.DeleteUser(userId);
}

void MainWindow::on_returnManageAccountsButton_clicked()
{
    goBack();
}

// ---------------- UPDATE ACCOUNT PAGE ----------------
void MainWindow::on_createAccountUpdateAccountButton_clicked()
{
    // zapisz zmiany konta
}

void MainWindow::on_returnUpdateAccountButton_clicked()
{
    goBack();
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
    goBack();
}

//-------------ACCOUNTS PAGE METHODS---------
void MainWindow::resetAccountsPageState()
{
    refreshAccountsTable();
    ui->loginAccountsButton->setEnabled(false);
}

void MainWindow::refreshAccountsTable() {
    ui->accountsTableWidget->clearContents();
    ui->accountsTableWidget->setRowCount(0);

    UserController userController;
    std::vector<User> users = userController.getUsers();

    for (const User& user : users) {
        int currentRow = ui->accountsTableWidget->rowCount();
        ui->accountsTableWidget->insertRow(currentRow);

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(user.getId()));
        QTableWidgetItem* nameItem = new QTableWidgetItem(user.getName());
        QTableWidgetItem* roleItem = new QTableWidgetItem(user.getRole() == 0 ? "Gracz" : "Admin");

        ui->accountsTableWidget->setItem(currentRow, 0, idItem);
        ui->accountsTableWidget->setItem(currentRow, 1, roleItem);
        ui->accountsTableWidget->setItem(currentRow, 2, nameItem);
    }
}

void MainWindow::onAccountRowSelected() {
    ui->loginAccountsButton->setEnabled(true);
}

void MainWindow::validateCreateAccountForm()
{
    QString name = ui->accountNameAccountCreateLineEdit->text();
    bool isNameValid = !name.isEmpty() && name.length() <= 50;
    bool isRoleSelected = ui->playerRoleRadioButton->isChecked() || ui->adminRoleRadioButton->isChecked();

    ui->createAccountCreateAccountButton->setEnabled(isNameValid && isRoleSelected);
}

// --------------UTILITY METHODS------------
void MainWindow::jumpTo(int pageIndex)
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex != pageIndex) {
        pageStack.push(currentIndex); // save page before jumping into next
        ui->stackedWidget->setCurrentIndex(pageIndex);
    }
}

void MainWindow::goBack()
{
    if (!pageStack.isEmpty()) {
        int previousPage = pageStack.pop();
        ui->stackedWidget->setCurrentIndex(previousPage);
    } else {
        ui->stackedWidget->setCurrentIndex(HOME_PAGE);
    }
}
