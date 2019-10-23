#ifndef SDL_EVENT_TO_STRING_H
#define SDL_EVENT_TO_STRING_H

#include "SDL_events.h"

#ifdef __cplusplus
extern "C" {
#endif

char *sdlEventToCString(char *dst, size_t n, const SDL_Event *event);

void sdlEventToSdlLog(const SDL_Event *event);

#ifdef __cplusplus
}
#endif

#endif
