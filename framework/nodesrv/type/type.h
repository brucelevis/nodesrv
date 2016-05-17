#ifndef _TYPE_H_
#define _TYPE_H_

//tolua_begin
class Type
{
public:
    Type(const char* name);
    char name[64];
};
//tolua_end

#define DECLAR(classname) \
    public:\
    virtual Type* get_type();\
    virtual const char* get_type_name();\
    static Type* type;

#define IMPLEMENT(classname) \
    Type* classname::type = new Type(#classname);\
    Type* classname::get_type()\
    {\
        return classname::type;\
    }\
    const char* classname::get_type_name()\
    {\
        return classname::type->name;\
    }

#endif
