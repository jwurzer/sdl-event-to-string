#ifndef SDL_EVENTS_PRINT
#define SDL_EVENTS_PRINT

#include "SDL_events.h"

#ifdef __cplusplus
extern "C" {
#endif

char *sdlEventToCString(char *dst, size_t n, const SDL_Event *event);

void sdlEventToConsole(const SDL_Event *event);

#ifdef __cplusplus
}
#endif

#endif
