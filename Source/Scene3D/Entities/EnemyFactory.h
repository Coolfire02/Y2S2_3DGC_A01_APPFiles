/**
 EnemyFactory
 */
#pragma once

// Include GLM
#include <includes/glm.hpp>
#include <includes/gtc/matrix_transform.hpp>
#include <includes/gtc/type_ptr.hpp>

//Include Enemy
#include "Enemy3D.h"

#include <string>
using namespace std;

// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class EnemyFactory
{
public:
	
    static CEnemy3D* CreatePistolEnemy(glm::vec2 xzposition, glm::vec3 facing, float speed);
    static CEnemy3D* CreateMeleeEnemy(glm::vec2 xzposition, glm::vec3 facing, float speed, CSolidObject* target, float meleeDamage, float meleeAttackCooldown);

};
