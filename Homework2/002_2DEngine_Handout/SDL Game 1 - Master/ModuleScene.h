#pragma once
#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL.h"
#include <Vector>

class ModuleTextures;
class ModuleRender;

struct SDL_Texture;
class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	void Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	void MoveCameraRight();
	void MoveCameraLeft();
	bool CleanUp();

private:
	SDL_Rect*				m_background;
	SDL_Rect*				m_floor;
	std::vector<SDL_Rect*>	m_flag;
	SDL_Texture*			m_texture;

	int					m_cameraX;
	int					m_cameraY;
	int					m_textureFlag;

};

