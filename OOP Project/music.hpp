#pragma once
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <SDL.h>
#include <string>

class Music
{
private:
    Mix_Music *bgMusic = NULL;
    Mix_Chunk *chunk = NULL;

public:
    Music()
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
        {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }
    }

    // for audio files
    void LoadingMusic(const std::string &musicfile);
    // for audio files
    void LoadingSoundEffect(const std::string &soundfile);
    // for background music
    void PlayMusic();
    // for pausing music
    void PauseMusic();
    // for soundeffects
    void PlaySoundEffect();

    // deconstructor
    ~Music()
    {
        Mix_FreeChunk(chunk);
        Mix_FreeMusic(bgMusic);
        bgMusic = nullptr;
        chunk = nullptr;
        Mix_Quit();
    }
};