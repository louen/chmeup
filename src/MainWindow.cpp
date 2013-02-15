#include "MainWindow.h"
#include "constants.h"
#include <QMenuBar>
#include <QMenu>
#include <QApplication>


extern int screenWidthGlobal;
extern int screenHeightGlobal;

MainWindow::MainWindow( GameEngine * currentEngine) :
 isGameLaunched(false),keystate()
{
  currentGameEngine = currentEngine ;

  // menubar creation
  menuBar = new QMenuBar();
  QMenu * gameMenu = menuBar->addMenu("Game");
  gameMenu->addAction("New Game",this,SLOT(diplayNewGame()));
  gameMenu->addAction("Stop Game",currentGameEngine, SLOT(stop()));
  gameMenu->addAction("Options",this, SLOT(displayOptions()));
  gameMenu->addSeparator();
  gameMenu->addAction("Quit",qApp,SLOT(quit()));
  QMenu * helpMenu = menuBar->addMenu("Help");
  helpMenu->addAction("About chmeup",this,SLOT(displayAbout()));

  setFixedSize(screenWidthGlobal + 2 * BORDER_WIDTH ,screenHeightGlobal + menuBar->sizeHint().height() + 2* BORDER_HEIGHT);

  // central widget
  setCentralWidget(&screen);

  connect(currentGameEngine, SIGNAL(updateUI()), this, SLOT(update())) ;
  connect(currentGameEngine, SIGNAL(requestKeyUI()),this,SLOT(keysNeeded()));
  connect(currentGameEngine, SIGNAL(displayGameOverScreen()), this, SLOT(gameOverDisplay()));
  connect(currentGameEngine, SIGNAL(displayGameWonScreen()),this,SLOT(gameWonDisplay()));
  connect(this,SIGNAL(sendKeys(KeyPressedFrame * )),currentGameEngine,SLOT(getKeyFrame(KeyPressedFrame *)));
  connect(this,SIGNAL(sendPause()), currentGameEngine, SLOT(pause()));

  setMenuBar(menuBar);

}


void MainWindow::diplayNewGame()
{
    QStringList difficultyStringList;
    difficultyStringList << "Normal" << "Nightmare" << "Hell" ;

    QString text;
    bool ok ;
    text = QInputDialog::getItem(this, "New Game", "Set Difficulty Level", difficultyStringList, 0 , false , &ok);

    if(text == QString("Normal"))
         currentGameEngine->setDifficultyLevel(1);
   else if (text == QString("Nightmare"))
         currentGameEngine->setDifficultyLevel(2);
   else if (text == QString("Hell"))
         currentGameEngine->setDifficultyLevel(3);
   else
         currentGameEngine->setDifficultyLevel(1);
   if(ok)
   {
       isGameLaunched  = true ;
       currentGameEngine->start();
   }
 }

void MainWindow::displayAbout()
{
    aboutBox.setWindowTitle("About chmeup");
    aboutBox.setText("<b>&copy; 2011 The chmeup project</b>");
    aboutBox.setInformativeText("All your base are belong to us.\nDoggy, Louen, PG and Tisca powered");
    aboutBox.show() ;
}

void::MainWindow::displayOptions()
{
    QStringList resolutionStringList;
    resolutionStringList << "600x600" << "800x800" << "800x1000" ;

    QString text;
    bool ok ;
    text = QInputDialog::getItem(this, "Options", "Set Window Size", resolutionStringList, 0 , false , &ok);

    if(text == QString("600x600"))
    {
         screenWidthGlobal = 600 ;
         screenHeightGlobal = 600 ;
     }
   else if (text == QString("800x800"))
    {
       screenWidthGlobal = 800 ;
       screenHeightGlobal = 800 ;
   }
   else if (text == QString("800x1000"))
   {
       screenWidthGlobal = 1000 ;
       screenHeightGlobal = 800 ;
   }
   else
   {
       screenWidthGlobal = 600 ;
       screenHeightGlobal = 600 ;
   }
   if(ok)
   {
       setFixedSize(screenWidthGlobal + 2*BORDER_WIDTH , screenHeightGlobal + menuBar->sizeHint().height() + 2* BORDER_HEIGHT);
   }
}

void MainWindow::update()
{
  screen.update(currentGameEngine) ;
}

void MainWindow::keysNeeded()
{
  emit sendKeys(new KeyPressedFrame(keystate)) ;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
  if(isGameLaunched)
  {
      int currentKey = event->key() ;
      if(currentKey == keyType.upKey){
          event->accept();
          keystate.up = true ;
         }
      else if(currentKey == keyType.leftKey){
          event->accept();
          keystate.left = true ;
         }
      else if(currentKey == keyType.downKey){
          event->accept();
          keystate.down = true ;
         }
      else if(currentKey == keyType.rightKey){
          event->accept();
          keystate.right = true ;
         }
      else if(currentKey == keyType.shootKey){
          event->accept();
          keystate.shoot = true ;
         }
      else if(currentKey == keyType.pauseKey){
          event->accept();
          emit sendPause();
         }
      else
          event->ignore();
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
  if(isGameLaunched)
  {
      int currentKey = event->key() ;
      if(currentKey == keyType.upKey){
          event->accept();
          keystate.up = false ;
         }
      else if(currentKey == keyType.leftKey){
          event->accept();
          keystate.left = false ;
         }
      else if(currentKey == keyType.downKey){
          event->accept();
          keystate.down = false ;
         }
      else if(currentKey == keyType.rightKey){
          event->accept();
          keystate.right = false ;
         }
      else if(currentKey == keyType.shootKey){
          event->accept();
          keystate.shoot = false ;
         }
      else if(currentKey == keyType.pauseKey){
          event->accept();
         }
      else
          event->ignore();
    }
}

void MainWindow::gameOverDisplay()
{
    screen.gameOverScreen();
}

void MainWindow::gameWonDisplay()
{
    screen.gameWonScreen();
}

void MainWindow::setLocalConfig(QLocale * a_localConfig)
{
    localConfig = a_localConfig ;

    if(localConfig->language()== QLocale::French)//for AZERTY
    {
        keyType.upKey = Qt::Key_Z ;
        keyType.downKey = Qt::Key_S;
        keyType.leftKey = Qt::Key_Q ;
        keyType.rightKey = Qt::Key_D;
        keyType.shootKey = Qt::Key_Space ;
        keyType.pauseKey = Qt::Key_P;
    }
    else //We assume the other kinds of languages are for QWERTYs
    {
        keyType.upKey = Qt::Key_W ;
        keyType.downKey = Qt::Key_S;
        keyType.leftKey = Qt::Key_A ;
        keyType.rightKey = Qt::Key_D;
        keyType.shootKey = Qt::Key_Space ;
        keyType.pauseKey = Qt::Key_P;
    }
};
