#include "Item.h"

#include "System/LoadOBJ.h"
// Include ImageLoader
#include "System\ImageLoader.h"

#include <iostream>
using namespace std;

int Item::getQuantity()
{
	return this->quantity;
}

void Item::setQuantity(int amt)
{
	if(amt > 0 && amt < 999)
		this->quantity = amt;
}

void Item::changeQuantityBy(int change)
{
	this->quantity += change;
	if (quantity < 0) quantity = 0;
	else if (quantity > 999) quantity = 999;
}

Item::ITEM_TYPE Item::getItemType()
{
	return itemType;
}

void Item::setDisplayName(std::string display)
{
	this->displayName = display;
}

std::string Item::getDisplayName()
{
	return this->displayName;
}

Item::Item()
{

}

Item::Item(ITEM_TYPE type, std::string displayName)
{
	this->itemType = type;
	this->displayName = displayName;
}

Item::~Item()
{
}

bool Item::Init()
{
	// Call the parent's Init()
	CEntity3D::Init();

	// Set the type
	SetType(CEntity3D::TYPE::OTHERS);

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	std::vector<ModelVertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;

	std::string file_path = "Models/Pistol/gun_type64_01.obj";
	bool success = CLoadOBJ::LoadOBJ(file_path.c_str(), vertices, uvs, normals, true);
	if (!success)
	{
		cout << "Unable to load Models/Pistol/gun_type64_01.obj" << endl;
		return false;
	}

	//std::string file_path = "Models/Assault_Rifle/assault_rifle.obj";
	//bool success = CLoadOBJ::LoadOBJ(file_path.c_str(), vertices, uvs, normals, true);
	//if (!success)
	//{
	//	cout << "Unable to load Models/Assault_Rifle/assault_rifle.obj" << endl;
	//	return false;
	//}

	CLoadOBJ::IndexVBO(vertices, uvs, normals, index_buffer_data, vertex_buffer_data);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(ModelVertex), &vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	iIndicesSize = index_buffer_data.size();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ModelVertex), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(ModelVertex), (void*)(sizeof(glm::vec3) + sizeof(glm::vec3)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// load and create a texture 
	iTextureID = CImageLoader::GetInstance()->LoadTextureGetID("Models/Pistol/map_gunType64_01_AO.png", false);
	if (iTextureID == 0)
	{
		cout << "Unable to load Models/Pistol/map_gunType64_01_AO.png" << endl;
		return false;
	}
	return true;
}

/**
 @brief Set up the OpenGL display environment before rendering
 */
void Item::PreRender(void)
{
	// Change depth function so depth test passes when values are equal to depth buffer's content
	glDepthFunc(GL_LEQUAL);

	// Activate normal 3D shader
	CShaderManager::GetInstance()->Use(sShaderName);
}

/**
 @brief Render this instance
 */
void Item::Render(void)
{
	// note: currently we set the projection matrix each frame, but since the projection 
	// matrix rarely changes it's often best practice to set it outside the main loop only once.
	CShaderManager::GetInstance()->activeShader->setMat4("projection", projection);
	CShaderManager::GetInstance()->activeShader->setMat4("view", view);
	CShaderManager::GetInstance()->activeShader->setMat4("model", model);

	// bind textures on corresponding texture units
	glBindTexture(GL_TEXTURE_2D, iTextureID);
	glActiveTexture(GL_TEXTURE0);
	// Render the mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, iIndicesSize, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

/**
 @brief PostRender Set up the OpenGL display environment after rendering.
 */
void Item::PostRender(void)
{
	glDepthFunc(GL_LESS); // set depth function back to default
}