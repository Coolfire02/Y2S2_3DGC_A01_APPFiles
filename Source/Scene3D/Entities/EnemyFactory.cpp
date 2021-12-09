#include "EnemyFactory.h"

#include "../Terrain/Terrain.h"

//Weapons
#include "../WeaponInfo/Pistol.h"

#include "../Entities/SolidObjectManager.h"

CEnemy3D* EnemyFactory::CreatePistolEnemy(glm::vec2 position, glm::vec3 facing, float speed)
{
	float fCheckHeight = CTerrain::GetInstance()->GetHeight(position.x, position.y); //ITS X AND Z. Just that we use vec2 to use as pair
	glm::vec3 scale = glm::vec3(0.5, 0.9, 0.5);
	CEnemy3D* cEnemy3D = new CEnemy3D(glm::vec3(position.x, fCheckHeight + scale.y*2, position.y));
	cEnemy3D->SetScale(scale);
	cEnemy3D->SetShader("Shader3D");
	cEnemy3D->Init(CEnemy3D::GUNNER);
	cEnemy3D->InitCollider("Shader3D_Line", glm::vec4(1.f, 0.f, 0.f, 1.f));

	CPistol* cEnemyPistol = new CPistol();
	cEnemyPistol->SetScale(glm::vec3(1.75f, 1.75f, 1.75f));
	cEnemyPistol->Init();
	cEnemyPistol->SetShader("Shader3D_Model");
	cEnemy3D->SetWeapon(0, cEnemyPistol);
	cEnemy3D->SetTarget(CPlayer3D::GetInstance());
	CSolidObjectManager::GetInstance()->Add(cEnemy3D);

	return cEnemy3D;
}

CEnemy3D* EnemyFactory::CreateMeleeEnemy(glm::vec2 position, glm::vec3 facing, float speed, CSolidObject* target, float meleeDamage, float meleeAttackCD)
{
	float fCheckHeight = CTerrain::GetInstance()->GetHeight(position.x, position.y);
	glm::vec3 scale = glm::vec3(0.5, 0.9, 0.5);
	CEnemy3D* cEnemy3D = new CEnemy3D(glm::vec3(position.x, fCheckHeight + scale.y, position.y));
	cEnemy3D->SetScale(scale);
	cEnemy3D->SetShader("Shader3D");
	cEnemy3D->Init(CEnemy3D::MELEE);
	cEnemy3D->InitCollider("Shader3D_Line", glm::vec4(1.f, 0.f, 0.f, 1.f));
	cEnemy3D->SetTarget(target);
	cEnemy3D->setMeleeDamage(meleeDamage);
	cEnemy3D->setAttackCooldownDuration(meleeAttackCD);
	//Add weapon obj to display?
	CSolidObjectManager::GetInstance()->Add(cEnemy3D);

	return cEnemy3D;
}


