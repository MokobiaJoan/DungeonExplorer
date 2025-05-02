#include "MainWindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollBar>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      enemyHp_(80), enemyMaxHp_(80),
      mapString_(
        "+---+---+---+\n"
        "| @ |   | G |\n"
        "+---+---+---+\n"
        "|   | X |   |\n"
        "+---+---+---+\n"
      )
{
    showCharacterDialog();
    setupUi();

    // Intro narrative
    showStory({
        "You awaken in darkness, drenched in cold sweat.",
        "Your memory is hazy, but you know you must escape."
    });

    // First room description
    showStory({
        "You find yourself in a dimly lit dungeon chamber.",
        "A health potion glimmers on a dusty table."
    });
    inventory_.append("Health Potion");
    showStory({ "You pick up the Health Potion and add it to your inventory." });

    // Trap event
    playerHp_ = std::max(0, playerHp_ - 10);
    showStory({ "A hidden trap springs beneath your foot! You take 10 damage." });

    refreshMap();
    refreshStats();
    refreshInventory();
    appendLog(QString("Welcome, %1 the %2!").arg(playerName_, playerClass_));
}

MainWindow::~MainWindow() {}

void MainWindow::showCharacterDialog()
{
    QDialog dlg(this);
    dlg.setWindowTitle("Choose Your Hero");

    QVBoxLayout *vlay = new QVBoxLayout(&dlg);
    vlay->addWidget(new QLabel("Select class:"));
    QComboBox *combo = new QComboBox;
    combo->addItems({"Warrior", "Mage", "Rogue"});
    vlay->addWidget(combo);

    vlay->addWidget(new QLabel("Enter name:"));
    QLineEdit *nameEdit = new QLineEdit;
    vlay->addWidget(nameEdit);

    QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok);
    vlay->addWidget(buttons);
    connect(buttons, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);

    dlg.exec();
    playerClass_ = combo->currentText();
    playerName_  = nameEdit->text().trimmed();
    if (playerName_.isEmpty()) playerName_ = "Hero";

    if (playerClass_ == "Warrior") {
        playerMaxHp_   = 120; playerHp_   = 120;
        playerMaxMana_ = 30;  playerMana_ = 30;
    } else if (playerClass_ == "Mage") {
        playerMaxHp_   = 80;  playerHp_   = 80;
        playerMaxMana_ = 100; playerMana_ = 100;
    } else {
        playerMaxHp_   = 90;  playerHp_   = 90;
        playerMaxMana_ = 50;  playerMana_ = 50;
    }
}

void MainWindow::setupUi()
{
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    mapView_ = new QPlainTextEdit;
    mapView_->setReadOnly(true);
    mapView_->setFixedWidth(300);
    mainLayout->addWidget(mapView_);

    QVBoxLayout *rightLayout = new QVBoxLayout();

    nameLabel_ = new QLabel(QString("Name: %1").arg(playerName_));
    classLabel_ = new QLabel(QString("Class: %1").arg(playerClass_));
    rightLayout->addWidget(nameLabel_);
    rightLayout->addWidget(classLabel_);

    QHBoxLayout *statsLayout = new QHBoxLayout();
    statsLayout->addWidget(new QLabel("HP:"));
    hpBar_ = new QProgressBar; statsLayout->addWidget(hpBar_);
    statsLayout->addWidget(new QLabel("Mana:"));
    manaBar_ = new QProgressBar; statsLayout->addWidget(manaBar_);
    rightLayout->addLayout(statsLayout);

    QHBoxLayout *actionLayout = new QHBoxLayout();
    attackBtn_  = new QPushButton("Attack");
    specialBtn_ = new QPushButton("Special");
    actionLayout->addWidget(attackBtn_);
    actionLayout->addWidget(specialBtn_);
    rightLayout->addLayout(actionLayout);

    QHBoxLayout *useLayout = new QHBoxLayout();
    itemInput_  = new QLineEdit;
    itemInput_->setPlaceholderText("Item name");
    useItemBtn_ = new QPushButton("Use Item");
    useLayout->addWidget(itemInput_);
    useLayout->addWidget(useItemBtn_);
    rightLayout->addLayout(useLayout);

    rightLayout->addWidget(new QLabel("Inventory:"));
    inventoryList_ = new QListWidget;
    rightLayout->addWidget(inventoryList_);

    rightLayout->addWidget(new QLabel("Log:"));
    logView_ = new QTextEdit; logView_->setReadOnly(true);
    rightLayout->addWidget(logView_, 1);

    mainLayout->addLayout(rightLayout);
    setCentralWidget(central);
    setWindowTitle("Dungeon Explorer GUI");

    connect(attackBtn_,  &QPushButton::clicked, this, &MainWindow::onAttack);
    connect(specialBtn_, &QPushButton::clicked, this, &MainWindow::onSpecial);
    connect(useItemBtn_, &QPushButton::clicked, this, &MainWindow::onUseItem);
}

void MainWindow::showStory(const QStringList &story)
{
    for (const QString &line : story)
        appendLog(line);
}

void MainWindow::appendLog(const QString &text)
{
    logView_->append(text);
    logView_->verticalScrollBar()->setValue(logView_->verticalScrollBar()->maximum());
}

void MainWindow::refreshStats()
{
    hpBar_->setRange(0, playerMaxHp_);
    hpBar_->setValue(playerHp_);
    manaBar_->setRange(0, playerMaxMana_);
    manaBar_->setValue(playerMana_);
}

void MainWindow::refreshInventory()
{
    inventoryList_->clear();
    for (const QString &it : inventory_)
        inventoryList_->addItem(it);
}

void MainWindow::refreshMap()
{
    mapView_->setPlainText(mapString_);
}

void MainWindow::onAttack()
{
    if (enemyHp_ <= 0) { appendLog("No enemy to attack."); return; }
    int dmg = 20; enemyHp_ = std::max(0, enemyHp_ - dmg);
    appendLog(QString("You attack for %1 damage.").arg(dmg));
    if (enemyHp_ == 0) appendLog("Enemy defeated!");
    else {
        int edmg = 10; playerHp_ = std::max(0, playerHp_ - edmg);
        appendLog(QString("Enemy hits you for %1 damage.").arg(edmg));
    }
    refreshStats();
}

void MainWindow::onSpecial()
{
    if (enemyHp_ <= 0) { appendLog("No enemy to use special on."); return; }
    int cost = 0, dmg = 0;
    if (playerClass_ == "Warrior") { cost = 5;  dmg = 25; }
    else if (playerClass_ == "Mage")   { cost = 20; dmg = 40; }
    else                               { cost = 10; dmg = 30; }
    if (playerMana_ < cost) { appendLog("Not enough mana."); return; }
    playerMana_ -= cost;
    enemyHp_ = std::max(0, enemyHp_ - dmg);
    appendLog(QString("You use special (%1 MP) for %2 damage.").arg(cost).arg(dmg));
    if (enemyHp_ == 0) appendLog("Enemy defeated!");
    else {
        int edmg = 15; playerHp_ = std::max(0, playerHp_ - edmg);
        appendLog(QString("Enemy strikes back for %1 damage.").arg(edmg));
    }
    refreshStats();
}

void MainWindow::onUseItem()
{
    QString item = itemInput_->text().trimmed();
    if (item.isEmpty()) { appendLog("Enter an item name."); return; }
    int restored = 0;
    if (item == "Health Potion" && playerHp_ < playerMaxHp_) {
        restored = 30; playerHp_ = std::min(playerHp_ + restored, playerMaxHp_);
    } else if (item == "Mana Potion" && playerMana_ < playerMaxMana_) {
        restored = 20; playerMana_ = std::min(playerMana_ + restored, playerMaxMana_);
    } else {
        appendLog("Cannot use that item now."); return;
    }
    appendLog(QString("You use %1 and restore %2 points.").arg(item).arg(restored));
    inventory_.removeOne(item);
    itemInput_->clear();
    refreshStats();
    refreshInventory();
}