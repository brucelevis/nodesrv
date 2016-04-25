#ifndef _SKILL_SYSTEM_H_
#define _SKILL_SYSTEM_H_

class SkillSystem : public Component
{
    public:
        SkillSystem();
        virtual ~SkillSystem();

        virtual int recv(MsgHeader* header, const char* data, size_t size);
    private:

};


#endif
