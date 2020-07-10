#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Main.h"

class Character
{
public:

	virtual void Init(float X, float Y) = 0;

	virtual void Update() = 0;

	virtual void Move() = 0;



	enum class KEY {
		RIGHT,
		DOWN,
		LEFT,
		UP,
		STOP,
	};



	enum class CHAR {
		LEFT_CHAR,
		RIGHT_CHAR
	};




	float x, y, tu, tv;
	int forward_row, forward_col;
	KEY  move_key, next_movekey;

};

#endif // CHARACTER_H_




