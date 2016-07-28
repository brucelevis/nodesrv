#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "component/component.h"
#include "display/vector3.h"
#include <map>

class Transform : public Component {//tolua_export
    public:
        Transform();//tolua_export
        virtual ~Transform();//tolua_export

    public:
        Vector3 position;//tolua_export
        Vector3 scale;//tolua_export
        Vector3 rotation;//tolua_export
        DECLAR(Transform);

};//tolua_export

#endif
