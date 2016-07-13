#include "scenesrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(SceneSrv)

SceneSrv::SceneSrv()
{

}

SceneSrv::~SceneSrv()
{

}

void SceneSrv::awake()
{
    LOG_DEBUG("SceneSrv::awake");
}

int SceneSrv::recv(Message* msg)
{
    return 0;
}



