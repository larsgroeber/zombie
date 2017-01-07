
#ifndef ZOMBIE_COLLISION_MANAGER_H
#define ZOMBIE_COLLISION_MANAGER_H


#include <vector>
#include <jaogll/sprite.h>
#include "agent.h"

class Collision_Manager
{
public:
    void set_level ( const std::vector<JOGL::Sprite>& _level );

    void set_agents ( const std::vector<Agent*>& _agents );

    /**
     * \brief Returns the agent the given agent collided with, or a nullptr if none was encountered.
     * \param agent
     * \return Agent*
     */
    Agent* collide ( Agent* agent );

private:
    std::vector<JOGL::Sprite> _level;
    std::vector<Agent*> _agents;

    /**
     * \brief Returns direction at which a rectangle 'rec' will get hit (perpendicular to its sides)
     *        or (0,0) if rectangle will not get hit in the next frame and the position of this hit.
     * \param agent  The agent to check
     * \param rec    The rectangle
     * \return glm::vec2
     */
    std::pair<glm::vec2,glm::vec2> get_hit_pos_and_dir ( Agent* agent, glm::vec4 rec ) const;

    bool is_in_interval ( float x, float a, float b ) const;
};


#endif //ZOMBIE_COLLISION_MANAGER_H
