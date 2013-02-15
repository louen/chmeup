#include "KeyPressedFrame.h"

KeyPressedFrame::KeyPressedFrame(bool up_a,bool down_a,bool left_a,bool right_a,bool shoot_a):
up(up_a),down(down_a),left(left_a),right(right_a),shoot(shoot_a)
{
}

KeyPressedFrame::KeyPressedFrame() :
up(false),down(false),left(false),right(false),shoot(false)
{
}
