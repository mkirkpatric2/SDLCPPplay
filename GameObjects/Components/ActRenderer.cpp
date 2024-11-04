//
// Created by M on 9/28/2024.
//

#include "ActRenderer.h"

ActRenderer::ActRenderer(SDL_Renderer *rend,std::vector<std::string> paths) {
    imgPaths = paths;
    loadTextures(rend);
    setObjectTexture(0);
}

void ActRenderer::renderActor(SDL_Renderer *rend, SDL_Rect *rect) {
    SDL_RenderCopy(rend, renderTexture, NULL, rect);
}

void ActRenderer::renderTile(SDL_Renderer *rend, SDL_Rect *rect, int r, int g, int b) {
    SDL_SetRenderDrawColor(rend, r, g, b, 255);
    SDL_RenderFillRect(rend, rect);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

}

void ActRenderer::setObjectTexture(int frame) {
// Don't think i'll organize it such that I am running a function to pull the proper
// Texture as needed, BUT for now, gonna set it this way.
    renderTexture = actorTextures[frame];

}

void ActRenderer::loadTextures(SDL_Renderer *rend) {
    //Load textures and store in vector for each file path for a given object.
    for (auto& path : imgPaths){
        actorTextures.push_back(SDL_CreateTextureFromSurface(rend, IMG_Load(path.c_str())));
    }
}


