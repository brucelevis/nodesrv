#ifndef _UNITY_FRAME_H_
#define _UNITY_FRAME_H_
#include "unityframe.pb.h"

/*
 * 这是打包给前端的一帧
 * 通过UDP下发
 */

class UnityFrame {//tolua_export
    public:
        UnityFrame(){};//tolua_export
        ~UnityFrame(){};//tolua_export
        //移动
        void move(int objectid, float src_x, float src_y, float src_z, float dst_x, float dst_y, float dst_z);//tolua_export

        //缩放
        void scale(int objectid, float src_x, float src_y, float src_z, float dst_x, float dst_y, float dst_z);//tolua_export

        //旋转
        void rorate(int objectid, float src_x, float src_y, float src_z, float dst_x, float dst_y, float dst_z);//tolua_export

        //新建gameobject
        void instantiate(const char* prefab, int objectid, const char* objname);//tolua_export

        //销毁gameobject
        void destroy(int objectid, int delay);//tolua_export

        //播放动画
        void play_anim(int objectid, const char* animname);//tolua_export

        //停止动画
        void stop_anim(int objectid, const char* animname);//tolua_export

    private:
        unity::FRAME frame;
};//tolua_export


#endif
