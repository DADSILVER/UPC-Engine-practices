#include "Application.h"
#include "ModuleScene.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"
#include <vector>


ModuleScene::ModuleScene()
{
	m_cameraX = 0;
	m_cameraY = 0;
	m_textureFlag = 0;
	m_background = new SDL_Rect;
	m_background->x = 72;
	m_background->y = 208;
	m_background->w = 768;
	m_background->h = 176;

	m_floor = new SDL_Rect;
	m_floor->x = 8;
	m_floor->y = 392;
	m_floor->w = 768;
	m_floor->h = 72 * 2;

	//m_flag = new std::vector<SDL_Rect*>;
	m_flag.reserve(3);
	SDL_Rect* flag1 = new SDL_Rect;
	flag1->x = 848;
	flag1->y = 312;
	flag1->w = 40;
	flag1->h = 32;
	m_flag.push_back(flag1);
	
	SDL_Rect* flag2 = new SDL_Rect;
	flag2->x = 848;
	flag2->y = 264;
	flag2->w = 40;
	flag2->h = 32;	
	m_flag.push_back(flag2);
	
	SDL_Rect* flag3 = new SDL_Rect;
	flag3->x = 848;
	flag3->y = 216;
	flag3->w = 40;
	flag3->h = 32;
	m_flag.push_back(flag3);
}

ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init()
{
	m_texture = App->textures->Load("ken_stage.png");
	return true;
}

void ModuleScene::Start()
{
	

}

update_status ModuleScene::PreUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update()
{
	

	App->renderer->Blit(m_texture, (SCREEN_WIDTH - m_floor->w) / 2 + m_cameraX, SCREEN_HEIGHT * 0.75 - m_background->h - m_floor->h, m_background);
	
	App->renderer->Blit(m_texture, (SCREEN_WIDTH - m_floor->w) / 2 + m_cameraX, SCREEN_HEIGHT * 0.75 - m_floor->h , m_floor);

	int flag=0;
	if (m_textureFlag < 50)
	{
		flag = 0;
	}
	else if (m_textureFlag < 100)
	{
		flag = 1;
	}
	else if (m_textureFlag < 150) 
	{
		flag = 2;
	}
	else
	{
		m_textureFlag = 0;
	}


	App->renderer->Blit(m_texture, (560 + (SCREEN_WIDTH - m_floor->w) / 2 + m_cameraX), 16 + SCREEN_HEIGHT * 0.75 - m_background->h - m_floor->h, m_flag[flag]);
	m_textureFlag++;

	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate()
{
	return UPDATE_CONTINUE;
}

void ModuleScene::MoveCameraRight()
{
	if ((SCREEN_WIDTH - m_floor->w) / 2 < m_cameraX) 
	{
		m_cameraX--;
	}
}

void ModuleScene::MoveCameraLeft()
{
	if (-(SCREEN_WIDTH - m_floor->w) / 2 > m_cameraX)
	{
		m_cameraX++;
	}
}

bool ModuleScene::CleanUp()
{
	LOG("Freeing textures and Image library");

	delete m_background;
	delete m_floor;

	/*for (std::vector<SDL_Rect*>::iterator it = m_flag.begin(); it != m_flag.end(); ++it)
		delete(*it);*/

	m_flag.clear();

	SDL_DestroyTexture(m_texture);
	return true;
}
