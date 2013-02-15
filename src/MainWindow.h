#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "GameEngine.h"
#include "Screen.h"
#include "KeyPressedFrame.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QStringList>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLocale>


typedef struct s_keyType s_keyType;
struct s_keyType
{
    Qt::Key upKey;
    Qt::Key downKey;
    Qt::Key leftKey;
    Qt::Key rightKey;
    Qt::Key shootKey;
    Qt::Key pauseKey ;
};


//! MainWindow: GUI main window.
/*! This class is the main window of the program, in charge of displaying the UI
    menus and the game screen, as well as catchin user input.*/
class MainWindow : public QMainWindow
{
  Q_OBJECT

  public :
    MainWindow( GameEngine * currentEngine);
    void setLocalConfig(QLocale * a_localConfig);

  protected slots:
    /*void saveGame();
    void loadGame();*/
    void displayAbout();//!< displays the About... window
    void diplayNewGame();//!< display the new game Dialog
    void displayOptions();//!< display the option Dialog
    void keyPressEvent(QKeyEvent* event);//!< activated when a key is pressed, updates the KeyPressedFrame
    void keyReleaseEvent(QKeyEvent* event);//!< activatedy is releaes the KeyPressedFrame

    void update() ;//!< receiving updateUI from the game engine
    void keysNeeded() ; //!<receiving requestKeysUI from the game engine
    void gameOverDisplay();//!<receiving displayGameOverScreen from the game engine
    void gameWonDisplay();//!<receiving displayGameWonScreen from the game engine

  signals:
    void sendKeys(KeyPressedFrame * ) ; //!< send the keys to the game engine
    void sendPause(); //!<send a pause signal to the game engine
  protected :
    Screen screen;//!< The game screen
    GameEngine * currentGameEngine ;//!< The game engine
    bool isGameLaunched ; //!< A flag to tell if there is a game going on
    QMessageBox aboutBox ;//!< The dialog displaying About...
    KeyPressedFrame keystate ;//!< The state of the key pressed
    QMenuBar * menuBar ;//!< General menuBar
    s_keyType  keyType ; //!< Control Key Codes depending of keyboard layout
    QLocale * localConfig ; //!< local config of the application
};
#endif // MAINWINDOW_H
