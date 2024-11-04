//
// Created by M on 9/28/2024.
//

#ifndef TWODIMWALKGAME_ACTRENDERER_H
#define TWODIMWALKGAME_ACTRENDERER_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

class ActRenderer {
public:
    void loadTextures(SDL_Renderer *rend);
    void setObjectTexture(int frame);
    void renderActor(SDL_Renderer *rend, SDL_Rect *rect);
    ActRenderer(SDL_Renderer *rend,std::vector<std::string> paths);

    void renderTile(SDL_Renderer *rend, SDL_Rect *rect, int r, int g, int b);
private:
    std::vector<std::string> imgPaths;
    std::vector<SDL_Texture*> actorTextures;
    SDL_Texture* renderTexture{};

};


#endif //TWODIMWALKGAME_ACTRENDERER_H
