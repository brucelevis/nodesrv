#include "unityframe.h"

//销毁gameobject
void UnityFrame::destroy(int objectid, int delay)
{
    unity::DestroyAction* action = frame.add_destroy();
    action->set_objectid(objectid);
    action->set_delay(delay);
}

void UnityFrame::instantiate(const char* prefab, int objectid, const char* objname)
{
    unity::InstantiateAction* action = frame.add_instantiate();
    action->set_objectid(objectid);
    action->set_prefab(prefab);
    action->set_objname(objname);
}

void UnityFrame::move(int objectid, float src_x, float src_y, float src_z, float dst_x, float dst_y, float dst_z)
{
    unity::MoveAction* action = frame.add_move();
    action->set_objectid(objectid);

    unity::Vector3* src_pos = action->mutable_src_position();
    src_pos->set_x(src_x);
    src_pos->set_x(src_y);
    src_pos->set_x(src_z);

    unity::Vector3* dst_pos = action->mutable_dst_position();
    dst_pos->set_x(dst_x);
    dst_pos->set_x(dst_y);
    dst_pos->set_x(dst_z);
}

void UnityFrame::scale(int objectid, float src_x, float src_y, float src_z, float dst_x, float dst_y, float dst_z)
{
    unity::ScaleAction* action = frame.add_scale();
    action->set_objectid(objectid);

    unity::Vector3* src_scale = action->mutable_src_scale();
    src_scale->set_x(src_x);
    src_scale->set_x(src_y);
    src_scale->set_x(src_z);

    unity::Vector3* dst_scale = action->mutable_dst_scale();
    dst_scale->set_x(dst_x);
    dst_scale->set_x(dst_y);
    dst_scale->set_x(dst_z);
}

void UnityFrame::rorate(int objectid, float src_x, float src_y, float src_z, float dst_x, float dst_y, float dst_z)
{
    unity::RorateAction* action = frame.add_rorate();
    action->set_objectid(objectid);

    unity::Vector3* src_rorate = action->mutable_src_rorate();
    src_rorate->set_x(src_x);
    src_rorate->set_x(src_y);
    src_rorate->set_x(src_z);

    unity::Vector3* dst_rorate = action->mutable_dst_rorate();
    dst_rorate->set_x(dst_x);
    dst_rorate->set_x(dst_y);
    dst_rorate->set_x(dst_z);
}

void UnityFrame::play_anim(int objectid, const char* animname)
{
    unity::PlayAnimAction* action = frame.add_play_anim();
    action->set_objectid(objectid);
    action->set_animname(animname);
}

void UnityFrame::stop_anim(int objectid, const char* animname)
{
    unity::StopAnimAction* action = frame.add_stop_anim();
    action->set_objectid(objectid);
    action->set_animname(animname);
}

