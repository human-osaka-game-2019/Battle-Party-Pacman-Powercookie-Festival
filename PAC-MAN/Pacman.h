#ifndef PACMAN_H_
#define PACMAN_H_

#include "Character.h"

class Pacman:public Character
{
public:

	Pacman() {}

	virtual void Init(float X, float Y) override;

	virtual void Update() override;
	virtual void Move() override;

	int degree;
	int life;



};


#endif // !PACMAN_H_


