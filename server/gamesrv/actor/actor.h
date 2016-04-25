#ifndef _ACTOR_H_
#define _ACTOR_H_


class Actor : public Entity
{

    public:
        Actor();
        virtual ~Actor();

        virtual int save();
    private:
        SkillSystem* skill_sys_;
};

#endif
