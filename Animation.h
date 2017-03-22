#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 25

class Animation
{
public:
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];

private:
	float current_frame;
	int last_frame = 0;
	bool anim_end = false;

public:

	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}

	SDL_Rect& GetCurrentFrame()
	{
		anim_end = false;
		current_frame += speed;
		if (current_frame >= last_frame) {
			current_frame = 0;
			anim_end = true;
		}

		return frames[(int)current_frame];
	}

	bool getAnimationEnd() {
		return anim_end;
	}
};

#endif