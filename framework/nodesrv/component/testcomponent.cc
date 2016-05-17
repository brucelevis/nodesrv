
#include "component/testcomponent.h"
#include <stdio.h>

IMPLEMENT(TestComponent)

TestComponent::TestComponent()
{

}

TestComponent::~TestComponent()
{

}

int TestComponent::test()
{
    printf("TestComponent::test()\n");
    return 0;
}
