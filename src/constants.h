#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QBrush>

#define FRAME_RATE 60 //!< Frames per seconds

#define BOOM_TIMER 30//!< number of frames for the lifespan of an explosion

#define SPACE_SHIP_ACCELERATION_LIMIT 400  //!< pixel.kg.s-2

#define PLAYER_SPACE_SHIP_ROTATION_SPEED  3 //!< degres by frame
#define PLAYER_SPACE_SHIP_ACCELERATION_QUANTA 4000 //!< pixel.kg.s-2
#define PLAYER_SPACE_SHIP_DECELERATION_QUANTA 2000 //!<pixel.kg.s-2
#define PLAYER_SPACE_SHIP_FRICTION_COEF 0.996 //!< parameter governing slowing the player's ship
#define PLAYER_SPACE_SHIP_SPEED_LIMIT 250 //!<pixel.s-1
#define PLAYER_SPACE_SHIP_SHOOTING_RATE 15 //!< defalut number of frames between each shoot
#define PLAYER_SPACE_SHIP_HP 100 //!< default HP for the player space ship

#define ENEMY_SPACE_SHIP_ROTATION_SPEED  3 //!< degres by frame
#define ENEMY_SPACE_SHIP_ACCELERATION_QUANTA 4000 //!< pixel.kg.s-2
#define ENEMY_SPACE_SHIP_DECELERATION_QUANTA 2000 //!< pixel.kg.s-2
#define ENEMY_SPACE_SHIP_FRICTION_COEF 1 //!< parameter governing slowing the ennemies' ship
#define ENEMY_SPACE_SHIP_SPEED_LIMIT 250 //!<pixel.s-1
#define ENEMY_SPACE_SHIP_SHOOTING_RATE 30 //!< default number of frames between each shoot

#define GAME_OBJECT_SPEED_THRESHOLD 4 //!<pixel.s-1

#define BULLET_SPEED_LIMIT 700 //!<pixel.s-1
#define BULLET_FRICTION_COEF 1 //!< parameter governing slowing the bullets
#define BULLET_DAMAGE 10 //! damage inflicted by a bullet

#define POTATOES_SPEED_LIMIT 50 //!<pixel.s-1
#define POTATOES_FRICTION_COEF 1 //!< //!< parameter governing slowing the asteroids


//#define SCENE_WIDTH 600   // Width of the game window
//#define SCENE_HEIGHT 600 // Height of the game window

#define BORDER_WIDTH 2 // border size between MainWindow and Screen. Empirically determined on Linux/KDE
#define BORDER_HEIGHT 2// TODO : check on other systems or (better) find a way to determine it trough a method (louen)

#define DEG_TO_RAD 0.0174532925
#define RAD_TO_DEG 57.2956455

extern bool display_model ;
static const QBrush bgBrush(Qt::black);
static const QBrush objBrush(Qt::green);


#endif// CONSTANTS_H
