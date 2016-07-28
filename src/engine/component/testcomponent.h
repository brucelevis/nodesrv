#ifndef _TEST_COMPONENT_H_
#define _TEST_COMPONENT_H_

#include "component/component.h"
#include <map>

class TestComponent : public Component {//tolua_export
    public:
        TestComponent();//tolua_export
        virtual ~TestComponent();//tolua_export
        int test();//tolua_export

DECLAR(TestComponent);

};//tolua_export

#endif
