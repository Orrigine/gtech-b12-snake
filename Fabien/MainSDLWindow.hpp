#ifndef Window_HPP
#define Window_HPP
#include <SDL2/SDL.h>

class Window
{
public:
    Window();
    ~Window();
    int Init(const char *nameWindow, int posX, int posY, int rendererW, int rendererH, bool fullscreen);
    // SDL_Renderer *GetRenderer(void){};

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };
    // return this->renderer;
private:
    SDL_Window *window;
    bool isRunning;
    SDL_Rect srcR, dstR;
    SDL_Rect srcA, dstA; // à enlever si prob

    int dir;

    const char *lastKeyPressed = "";
    Uint32 frame_time_start = SDL_GetTicks();
    Uint32 frame_ime_interval = SDL_GetTicks() - frame_time_start;

protected:
    SDL_Renderer *renderer;
    SDL_Texture *snakeSprite;
    SDL_Texture *appleSprite; // à enlever si prob
};
#endif