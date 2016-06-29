#include "type/type.h"
#include <string.h>

Type::Type(const char* name)
{
    strcpy(this->name, name);
}
