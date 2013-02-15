TARGET = chmeup
TEMPLATE = app
CONFIG += qt \
    debug_and_release \
    warn_on

# Directories
ROOT = $$PWD
SRC = $$ROOT/src
TMP = $$ROOT/tmp
BIN = $$ROOT/bin

# Files
SOURCES += $$SRC/ScenarioDemoLevel.cpp \
    $$SRC/Scenario.cpp \
    $$SRC/main.cpp \ # ======= GUI =============================
    $$SRC/MainWindow.cpp \
    $$SRC/Screen.cpp \
    $$SRC/AnimatedObject.cpp \
    $$SRC/KeyPressedFrame.cpp \ # ======= Game Engine =====================
    $$SRC/GameEngine.cpp \
    $$SRC/GameObject.cpp \
    $$SRC/SpaceShip.cpp \
    $$SRC/PlayerSpaceShip.cpp \
    $$SRC/Bullet.cpp \
    $$SRC/EnemySpaceShip.cpp \
    $$SRC/PlayerSpaceShipFactory.cpp \
    $$SRC/BulletFactory.cpp \
    $$SRC/EnemySpaceShipFactory.cpp \
    $$SRC/CollisionDetector.cpp \
    $$SRC/CollisionSolver.cpp \
    $$SRC/AnimatedShip.cpp \
    $$SRC/AnimatedBullet.cpp \
    $$SRC/AnimatedPotatoes.cpp \
    $$SRC/Potatoes.cpp \
    $$SRC/PotatoesFactory.cpp \
    $$SRC/SpaceShipCollision.cpp \
    $$SRC/BulletCollision.cpp \
    $$SRC/PotatoesCollision.cpp \
    $$SRC/AnimatedBoom.cpp \
    $$SRC/Boom.cpp \
    $$SRC/BoomFactory.cpp \
    $$SRC/BoomCollision.cpp
HEADERS += $$SRC/ScenarioDemoLevel.h \
    $$SRC/Scenario.h \
    $$SRC/Constants.h \ # ======= GUI =============================
    $$SRC/MainWindow.h \
    $$SRC/Screen.h \
    $$SRC/AnimatedObject.h \
    $$SRC/KeyPressedFrame.h \ # ======= Game Engine =====================
    $$SRC/GameEngine.h \
    $$SRC/GameObject.h \
    $$SRC/SpaceShip.h \
    $$SRC/PlayerSpaceShip.h \
    $$SRC/Bullet.h \
    $$SRC/EnemySpaceShip.h \
    $$SRC/BulletFactory.h \
    $$SRC/EnemySpaceShipFactory.h \
    $$SRC/GameObjectFactory.h \
    $$SRC/SpaceShipFactory.h \
    $$SRC/PlayerSpaceShipFactory.h \
    $$SRC/CollisionDetector.h \
    $$SRC/CollisionSolver.h \
    $$SRC/AnimatedShip.h \
    $$SRC/AnimatedBullet.h \
    $$SRC/AnimatedPotatoes.h \
    $$SRC/Potatoes.h \
    $$SRC/PotatoesFactory.h \
    $$SRC/GameObjectCollision.h \
    $$SRC/SpaceShipCollision.h \
    $$SRC/BulletCollision.h \
    $$SRC/PotatoesCollision.h \
    $$SRC/AnimatedBoom.h \
    $$SRC/Boom.h \
    $$SRC/BoomFactory.h \
    $$SRC/BoomCollision.h

# config release
MOC_DIR = $$TMP/release/moc
OBJECTS_DIR = $$TMP/release/obj
DESTDIR = $$BIN/release

# config debug in separate directories
build_pass:CONFIG(debug,debug|release) {
    MOC_DIR = $$TMP/debug/moc
    OBJECTS_DIR = $$TMP/debug/obj
    DESTDIR = $$BIN/debug
}
