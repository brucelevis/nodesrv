#include "logicsrv.h"
#include "stdafx.h"
#include <stdio.h>

IMPLEMENT(LogicSrv)

LogicSrv::LogicSrv()
{

}

LogicSrv::~LogicSrv()
{

}


void LogicSrv::awake()
{
    LOG_DEBUG("LogicSrv::awake");
}

int LogicSrv::recv(Message* msg)
{
    return 0;
}


