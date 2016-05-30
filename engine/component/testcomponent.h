#ifndef _TEST_COMPONENT_H_
#define _TEST_COMPONENT_H_

#include "component/component.h"
#include <map>

//tolua_begin
class TestComponent : public Component
{
    public:
        TestComponent();
        virtual ~TestComponent();
        int test();
//tolua_end

DECLAR(TestComponent);

};//tolua_export

#endif
