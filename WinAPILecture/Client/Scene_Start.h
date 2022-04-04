#pragma once
#include "CScene.h"
class Scene_Start :
    public CScene
{
public:
    virtual void update();
    virtual void Enter();
    virtual void Exit();

public:
    Scene_Start();
    ~Scene_Start();
};

