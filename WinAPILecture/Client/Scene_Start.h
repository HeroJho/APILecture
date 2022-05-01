#pragma once
#include "CScene.h"

class CSpawner;

class Scene_Start :
    public CScene
{
private:
    CSpawner* m_pSpawner;

public:
    void MakeUI();

public:
    virtual void update();
    virtual void Enter();
    virtual void Exit();

public:
    Scene_Start();
    ~Scene_Start();
};

