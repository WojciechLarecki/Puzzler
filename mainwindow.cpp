#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "./Controllers/databasecontroller.h"
#include "./Controllers/usercontroller.h"

#include <QPushButton>
#include <QVector>
#include <QRandomGenerator>
#include <algorithm>
#include <QDebug>
#include <QTimer>


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

    // accountsTableWidget
    ui->accountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->accountsTableWidget->setColumnHidden(0, true); // hide Id column
    ui->accountsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->accountsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->accountsTableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onAccountRowSelected);

    // manageAccountsTableWidget
    ui->manageAccountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->manageAccountsTableWidget->setColumnHidden(0, true); // hide Id column
    ui->manageAccountsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->manageAccountsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->manageAccountsTableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onManageAccountsRowSelected);

    // updateAccountPage
    ui->userIdUpdateAccountLabel->setHidden(true);

    connect(ui->accountNameAccountCreateLineEdit, &QLineEdit::textChanged, this, &MainWindow::validateCreateAccountForm);
    connect(ui->playerRoleRadioButton, &QRadioButton::toggled, this, &MainWindow::validateCreateAccountForm);
    connect(ui->adminRoleRadioButton, &QRadioButton::toggled, this, &MainWindow::validateCreateAccountForm);

    connect(ui->returnGameResultsButton, &QPushButton::clicked, this, &MainWindow::goBack);

    // gamePage
    // timer
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(ui->resetGameButton, &QPushButton::clicked, this, [=]() {
        initializeGameBoard(boardSize);
    });


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
    jumpTo(DIFFICULTY_PAGE);
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_loginButton_clicked()
{
    resetAccountsPageState();
    jumpTo(ACCOUNTS_PAGE);
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
    refreshManageAccountsTable();
    ui->deleteManageAccountsButton->setEnabled(false);
    ui->editManageAccountsButton->setEnabled(false);
    jumpTo(MANAGE_ACCOUNTS_PAGE);
}

void MainWindow::on_returnAdminButton_clicked()
{
    goBack();
}

// ---------------- MANAGE ACCOUNTS PAGE ----------------
void MainWindow::on_editManageAccountsButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->manageAccountsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano żadnego użytkownika.");
        return;
    }

    // read selected user
    int selectedRow = ui->manageAccountsTableWidget->currentRow();
    QTableWidgetItem* userIdItem = ui->manageAccountsTableWidget->item(selectedRow, 0);
    QTableWidgetItem* userRoleItem = ui->manageAccountsTableWidget->item(selectedRow, 1);
    QTableWidgetItem* userNameItem = ui->manageAccountsTableWidget->item(selectedRow, 2);

    User user;
    user.setId(userIdItem->text().toInt());
    user.setName(userNameItem->text());
    if (userRoleItem->text() == "Gracz") {
        user.setRole(0);
    }
    else
        user.setRole(1);


    fillUpdateAccountPage(user);
    jumpTo(UPDATE_ACCOUNT_PAGE);
}

void MainWindow::on_deleteManageAccountsButton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->manageAccountsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano żadnego użytkownika.");
        return;
    }

    int selectedRow = ui->manageAccountsTableWidget->currentRow();
    QTableWidgetItem* userIdItem = ui->manageAccountsTableWidget->item(selectedRow, 0);

    int userId = userIdItem->text().toInt();

    UserController userController;
    userController.DeleteUser(userId);

    // reset page state
    refreshManageAccountsTable();
    ui->deleteManageAccountsButton->setEnabled(false);
    ui->editManageAccountsButton->setEnabled(false);

    //TODO dodać nie usuwanie swojego konta.
}

void MainWindow::onManageAccountsRowSelected() {
    ui->editManageAccountsButton->setEnabled(true);
    ui->deleteManageAccountsButton->setEnabled(true);
}

void MainWindow::on_returnManageAccountsButton_clicked()
{
    goBack();
}

void MainWindow::refreshManageAccountsTable() {
    ui->manageAccountsTableWidget->clearContents();
    ui->manageAccountsTableWidget->setRowCount(0);

    UserController userController;
    std::vector<User> users = userController.getUsers();

    for (const User& user : users) {
        int currentRow = ui->manageAccountsTableWidget->rowCount();
        ui->manageAccountsTableWidget->insertRow(currentRow);

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(user.getId()));
        QTableWidgetItem* nameItem = new QTableWidgetItem(user.getName());
        QTableWidgetItem* roleItem = new QTableWidgetItem(user.getRole() == 0 ? "Gracz" : "Admin");

        ui->manageAccountsTableWidget->setItem(currentRow, 0, idItem);
        ui->manageAccountsTableWidget->setItem(currentRow, 1, roleItem);
        ui->manageAccountsTableWidget->setItem(currentRow, 2, nameItem);
    }
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

void MainWindow::fillUpdateAccountPage(User user) {
    ui->accountNameUpdateAccountLineEdit->setText(user.getName());
    QString userIdText = QString::number(user.getId());
    ui->userIdUpdateAccountLabel->setText(userIdText);

    if (user.getRole() == 0)
        ui->playerRoleUpdateAccountRadioButton->setChecked(true);
    else
        ui->adminRoleAccoutUpdateRadioButton->setChecked(true);
}

void MainWindow::on_updateUpdateAccountButton_clicked() {
    User user;
    user.setName(ui->accountNameUpdateAccountLineEdit->text());
    user.setId(ui->userIdUpdateAccountLabel->text().toInt());

    if (ui->playerRoleUpdateAccountRadioButton->isChecked())
        user.setRole(0);
    else user.setRole(1);

    UserController controller;
    controller.UpdateUser(user);

    refreshManageAccountsTable();
    goBack();
}

// ---------------- DIFFICULTY PAGE ----------------
void MainWindow::on_easyDifficultyButton_clicked()
{
    // get 3x3 tiles game
    initializeGameBoard(3);
    jumpTo(GAME_PAGE);
}

void MainWindow::on_normalDifficultyButton_clicked()
{
    // get 4x4 tiles game
    initializeGameBoard(4);
    jumpTo(GAME_PAGE);
}

void MainWindow::on_hardDifficultyButton_clicked()
{
    // get 5x5 tiles game
    initializeGameBoard(5);
    jumpTo(GAME_PAGE);
}

void MainWindow::on_customDifficultyButton_clicked()
{
    int value = ui->customDifficultySpin->value();

    // get 'n' tiles game
    initializeGameBoard(value);
    jumpTo(GAME_PAGE);
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

// --------------GAME METHODS------------
void MainWindow::initializeGameBoard(int size) {
    boardSize = size;
    clearGameBoard();

    QVector<int> numbers;
    for (int i = 1; i < size * size; ++i)
        numbers.append(i);
    numbers.append(0); // 0 to szare puste pole

    // suffle numbers to make a game
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    gameButtons.resize(size);
    QGridLayout* grid = ui->gridLayout;

    for (int row = 0; row < size; ++row) {
        gameButtons[row].resize(size);
        for (int col = 0; col < size; ++col) {
            int val = numbers[row * size + col];
            QPushButton* btn = new QPushButton(val == 0 ? "" : QString::number(val));
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            btn->setFont(QFont("Arial", 16, QFont::Bold));

            if (val == 0) {
                btn->setStyleSheet("background-color: gray;");
                emptyRow = row;
                emptyCol = col;
            }

            btn->setProperty("row", row);
            btn->setProperty("col", col);
            connect(btn, &QPushButton::clicked, this, &MainWindow::handleTileClick);

            grid->addWidget(btn, row, col);
            gameButtons[row][col] = btn;
        }
    }

    // set game start date
    startDate = QDateTime::currentDateTime();

    // set timer
    elapsedTime = QTime(0, 0, 0);
    ui->timeEdit->setTime(elapsedTime);
    gameTimer->start(1000);
}

void MainWindow::handleTileClick() {
    QPushButton* clicked = qobject_cast<QPushButton*>(sender());
    int row = clicked->property("row").toInt();
    int col = clicked->property("col").toInt();

    // check if empty tile's neighbour is clicked
    if ((abs(row - emptyRow) == 1 && col == emptyCol) || (abs(col - emptyCol) == 1 && row == emptyRow)) {
        QPushButton* emptyBtn = gameButtons[emptyRow][emptyCol];

        // change to numbered tile
        emptyBtn->setText(clicked->text());
        emptyBtn->setStyleSheet("");

        // change to empty tile
        clicked->setText("");
        clicked->setStyleSheet("background-color: gray;");
        emptyRow = row;
        emptyCol = col;

        if (isSolved()) {

            // set game end date
            endDate = QDateTime::currentDateTime();

            // stop timer
            gameTimer->stop();

            QMessageBox::information(this, "Gratulacje!", "Udało Ci się rozwiązać układankę!");
        }
    }
}

bool MainWindow::isSolved() const {
    int count = 1;
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QPushButton* btn = gameButtons[row][col];
            QString text = btn->text();

            if (row == boardSize - 1 && col == boardSize - 1) {
                return text.isEmpty(); // empty tile should be at last position
            }

            if (text.toInt() != count)
                return false;
            count++;
        }
    }
    return true;
}

void MainWindow::updateTimer() {
    elapsedTime = elapsedTime.addSecs(1);
    ui->timeEdit->setTime(elapsedTime);
}

void MainWindow::clearGameBoard() {
    // delete buttons from layout and memory
    for (auto& row : gameButtons) {
        for (QPushButton* button : row) {
            ui->gridLayout->removeWidget(button);
            delete button;
        }
    }

    // clear buttons vector from false references
    gameButtons.clear();
}

