#ifndef _TEST_COMPONENT_H_
#define _TEST_COMPONENT_H_

#include "component/component.h"
#include <map>

//tolua_begin
class Transform : public Component
{
    public:
        Transform();
        virtual ~Transform();
//tolua_end

DECLAR(Transform);

};//tolua_export

#endif
