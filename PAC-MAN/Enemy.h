#ifndef ENEMY_H_
#define ENEMY_H_

#include "Character.h"


class Enemy :public Character
{
public:

	virtual void Init() override;

	virtual void Update() override;

	virtual void Move() override;

	int pop;
};






#endif // !ENEMY_H_
