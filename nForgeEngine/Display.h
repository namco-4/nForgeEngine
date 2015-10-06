#pragma once

#include <string>
#include <SDL2\SDL.h>

class Display {

public:
	Display(int, int, const std::string&);
	virtual ~Display();
	void Update();
	bool isClosed();
	void Clear(float, float, float, float);
protected:
private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

