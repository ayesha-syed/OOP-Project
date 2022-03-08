#include "music.hpp"

// loading the sound files
void Music::LoadingMusic(const std::string &musicfile)
{
    bgMusic = Mix_LoadMUS(musicfile.c_str());
    if (bgMusic == NULL)
    {
        printf("Unable to load music: %s \n", Mix_GetError());
    }
}

// loading the sound effects
void Music::LoadingSoundEffect(const std::string &soundfile)
{
    chunk = Mix_LoadWAV(soundfile.c_str());
}

// music playing on infinite loop
void Music::PlayMusic()
{
    if (Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic(bgMusic, -1);
    }
}

// to pause the background sound
void Music::PauseMusic()
{
    if (Mix_PlayingMusic())
    {
        Mix_PauseMusic();
    }
}

// to play the sound effects
void Music::PlaySoundEffect()
{
    Mix_PlayChannel(-1, chunk, 0);
}