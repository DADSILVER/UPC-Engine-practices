#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

void ModuleInput::Start()
{
}

// Called every draw update
update_status ModuleInput::Update()
{
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);

	// TODO 1: Make the application properly close when ESC is pressed (do not use exit())
	if (keyboard[SDL_SCANCODE_ESCAPE]) {
		printf("<RETURN> is pressed.\n");
		return UPDATE_STOP;
	}
	if (keyboard[SDL_SCANCODE_D]) {
		App->scene->MoveCameraRight();
		printf("<D> is pressed.\n");
	}
	if (keyboard[SDL_SCANCODE_A]) {
		App->scene->MoveCameraLeft();
		printf("<A> is pressed.\n");
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}