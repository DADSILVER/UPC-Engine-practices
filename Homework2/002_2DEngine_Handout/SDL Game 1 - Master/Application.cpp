#pragma once
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleScene.h"

using namespace std;

Application::Application()
{
	// Order matters: they will Init/start/update in this order
	modules.push_back(window = new ModuleWindow());
	modules.push_back(renderer = new ModuleRender());
	modules.push_back(textures = new ModuleTextures());
	modules.push_back(input = new ModuleInput());
	modules.push_back(scene = new ModuleScene() );

	// TODO 7: Create a new "scene" module that loads a texture and draws it on the screen

}

Application::~Application()
{
	// TODO 6: Free module memory. We should remove all App memory on close.
	
	for (list<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		delete(*it);
	}
}

bool Application::Init()
{
	bool ret = true;

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Init();

	return ret;
}

update_status Application::PreUpdate()
{
	update_status ret = UPDATE_CONTINUE;


	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PreUpdate();

	return update_status();
}


update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;


	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->Update();

	return ret;
}

update_status Application::PostUpdate()
{
	update_status ret = UPDATE_CONTINUE;


	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
	{
		if (*it != nullptr)
		{
			ret = (*it)->PostUpdate();
		}
	}
		

	return update_status();
}

bool Application::CleanUp()
{
	bool ret = true;

	for (list<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend() && ret; ++it)
	{
		ret = (*it)->CleanUp();
		delete *it;
	}
	modules.clear();
		

	return ret;
}
