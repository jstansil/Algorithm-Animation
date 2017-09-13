#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Rect.h"
#include "Sorter.h"
#include <vector>

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
	
	std::vector<int> arr; //variable length array to hold integers for sorting
	int result[3] = { 0, 0, 0 }; //result values detailing the indecies we stopped at
	int mode = 1; //0 for insertion, 1 for bubble, 2 for shell, 3 for selection
	int count = 0;
	double size; //size of array
	bool turbo = false; //tells computer to run sort automatically as fast as possible
	bool lines = true; //enable or disable line display
	
	Sorter sorter; //wrapper for sort functions


    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
};

#endif
