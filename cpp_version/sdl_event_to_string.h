#ifndef SDL_EVENT_TO_STRING_H
#define SDL_EVENT_TO_STRING_H

#include <string>
#include <SDL_events.h>

char *sdlEventToCString(char *dst, size_t n, const SDL_Event *event);

std::string sdlEventToString(const SDL_Event& event);

void sdlEventToSdlLog(const SDL_Event& event);

#endif

