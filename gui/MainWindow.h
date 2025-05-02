#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>

class QPlainTextEdit;
class QTextEdit;
class QListWidget;
class QProgressBar;
class QPushButton;
class QLineEdit;
class QLabel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onAttack();
    void onSpecial();
    void onUseItem();

private:
    QPlainTextEdit *mapView_;
    QProgressBar   *hpBar_;
    QProgressBar   *manaBar_;
    QTextEdit      *logView_;
    QListWidget    *inventoryList_;
    QPushButton    *attackBtn_;
    QPushButton    *specialBtn_;
    QPushButton    *useItemBtn_;
    QLineEdit      *itemInput_;
    QLabel         *nameLabel_;
    QLabel         *classLabel_;

    QString        playerName_;
    QString        playerClass_;
    int            playerHp_;
    int            playerMaxHp_;
    int            playerMana_;
    int            playerMaxMana_;
    int            enemyHp_;
    int            enemyMaxHp_;
    QString        mapString_;
    QStringList    inventory_;

    void showCharacterDialog();
    void setupUi();
    void showStory(const QStringList &story);
    void appendLog(const QString &text);
    void refreshStats();
    void refreshInventory();
    void refreshMap();
};

#endif