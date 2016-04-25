#include "actor/actor.h"

Actor::Actor()
{
    skill_sys_ = new SkillSystem();
    add_component(skill_sys_);
}

Actor::~Actor()
{

}

int Actor::save()
{
    return 0;
}
