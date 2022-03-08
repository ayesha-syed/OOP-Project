#include "game.hpp"
#include "supplycollector.hpp"
#include "music.hpp"
#include "text.hpp"

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Supply Collector", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	assets = loadTexture("assets.png");
	gTexture = loadTexture("welcomescreen.jpg");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}

void Game::close()
{
	SDL_DestroyTexture(gTexture);

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rvoid Game::writeText(std::string content, int fontSize, int xCo, int yCo, SDL_Color color) {
	}
	return newTexture;
}

// void Game::drawAllObjects(){
// 	cart.draw(gRenderer, assets);
// }

void Game::writeText(std::string content, int fontSize, int xCo, int yCo, SDL_Color color)
{
	Text text(gRenderer, "font_text.ttf", fontSize, content, color);
	text.display(xCo, yCo, gRenderer);
}

void Game::run()
{
	bool quit = false;
std:
	string curr_screen = "Home";
	SDL_Event e;

	SupplyCollector s1 = SupplyCollector(gRenderer, assets);

	while (!quit)
	{
		// playing background music
		bgSound.PlayMusic();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			/*Here we are working on the arrow keys which will 
			be used to move our cart. We will be using left and right arrow key for the movement
			of our cart on the screen by the player. */
			if (e.type == SDL_KEYDOWN)
			{
				SDL_Keycode key = e.key.keysym.sym;
				std::string direction = "";
				if (key == SDLK_UP)
					direction = "up";
				else if (key == SDLK_DOWN)
					direction = "down";
				else if (key == SDLK_RIGHT)
					direction = "right";
				else if (key == SDLK_LEFT)
					direction = "left";
				s1.moveCart(direction);
			}

			/*Over here we are working on the screens. Basically we have used coordinates to switch screens
			So for doing that we are first taking the functionality of mouse button which will handle the selection of options on the 
			main screen of our game. Main screen has the functions of play game, instructions and quit. */
			if (e.type == SDL_MOUSEBUTTONDOWN && curr_screen == "Home")
			{

				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse); //getting the functionality of mouse
				//SupplyCollector.createObject(xMouse, yMouse);

				/*
				Coordinates are being checked for play button. On the menu screen if player clicks somewhere on the play button the 
				screen will get switched and now instead of menu screen you will see play screen.
				*/
				if (xMouse > 552 && xMouse < 782 && yMouse > 267 && yMouse < 328)
				{
					gTexture = loadTexture("playscreen.jpg");
					mouseclick.PlaySoundEffect();
					curr_screen = "Play";
					// writeText("Score", 30, 700, 10, {255,255,255,0});
					//writeText(to_string(playerScore.getScore()), 20, 720, 45, {255,255,255,0});
				}

				//If mouse is clicked on the coordinates of instructions button instructions screen will appear.
				if (xMouse > 550 && xMouse < 778 && yMouse > 345 && yMouse < 409)
				{
					gTexture = loadTexture("instructionscreen.jpg");
					curr_screen = "Instructions";
					mouseclick.PlaySoundEffect();
				}

				//If exit button pressed the game will quit
				if (xMouse > 550 && xMouse < 782 && yMouse > 422 && yMouse < 481)
				{
					mouseclick.PlaySoundEffect();
					SDL_Quit();
				}
			}
			/*
			We also have put current screen that determines which screen is active at the moment. Here it checks 
			if current screen is instructions screen or not if it is then it will further get in to loops inside it.
			*/
			if (e.type == SDL_MOUSEBUTTONDOWN && curr_screen == "Instructions")
			{

				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				//SupplyCollector.createObject(xMouse, yMouse);

				/*
				Music effect given and also checked if back button has been pressed on instructions screen if yes
				the screen will again switch and player will go back to the menu screen.
				*/
				if (xMouse > 26 && xMouse < 150 && yMouse > 22 && yMouse < 62)
				{
					mouseclick.PlaySoundEffect();
					gTexture = loadTexture("welcomescreen.jpg");
					curr_screen = "Home";
				}
			}
			//If current screen is play screen it will look into this loop.
			if (e.type == SDL_MOUSEBUTTONDOWN && curr_screen == "Play")
			{

				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);

				//If exit pressed on playscreen it will exit the game.
				if (xMouse > 26 && xMouse < 156 && yMouse > 22 && yMouse < 66)
				{
					gTexture = loadTexture("welcomescreen.jpg");
					s1 = SupplyCollector(gRenderer, assets);
					curr_screen = "Home";
					mouseclick.PlaySoundEffect();
				}
			}

			bgSound.LoadingMusic("bg2.wav");
			mouseclick.LoadingSoundEffect("Mclick.wav");
		}
		SDL_RenderClear(gRenderer);						 //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); //Draws background to renderer
		//***********************draw the objects here********************

		//If current screen is play screen then create and draw objects of suply collector are called
		if (curr_screen == "Play")
		{
			SDL_Delay(6);
			s1.createObject();
			s1.drawObjects();
			writeText("Score", 40, 450, 10, {243, 225, 169});
			writeText(to_string(s1.Score), 30, 490, 50, {0, 0, 0});
			writeText("Life", 40, 900, 10, {243, 225, 169});
			writeText("x " + to_string(s1.Life), 30, 920, 50, {0, 0, 0});

			//Score is being checked here if the score becomes 100 and player still has lives left player wins.
			if (s1.Score >= 100 && s1.Life >= 1)
			{
				gTexture = loadTexture("winningscreen.jpg");
				curr_screen = "Win";
			}
			//Player looses if they are out of lives
			if (s1.Life <= 0)
			{
				gTexture = loadTexture("losingscreen.jpg");
				curr_screen = "loose";
			}
		}
		//****************************************************************
		SDL_RenderPresent(gRenderer); //displays the updated renderer
		//causes sdl engine to delay for specified miliseconds
	}
}