#ifndef KEY_PRESSED_FRAME_H
#define KEY_PRESSED_FRAME_H
//!KeyPressedFrame : container for key pressed information

/*! This class is used by the GUI to send the information about which key were pressed
    by the player to the GameEngine. */
class KeyPressedFrame {
  public:
    bool up;
    bool down ;
    bool left ;
    bool right ;
    bool shoot ;
    KeyPressedFrame(bool up_a,bool down_a,bool left_a,bool right_a,bool shoot_a);
    KeyPressedFrame();
};
#endif // KEY_PRESSED_FRAME_H
