#include <iostream>
#include "App.h"



using namespace std;
App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
	cout << "				Algo Blast" << endl;
	cout << "				 Made By:" << endl;
	cout << "				  SCOOB" << endl;
	cout << "		     Super Cool Object Oriented Buddies" << endl;
	cout << endl;

	cout << "Welcome to Algo Blast, choose one of the following modes to get started:" << endl;
	cout << endl;
	cout << "	[0] Insertion Sort" << endl;
	cout << "	[1] Bubble Sort" << endl;
	cout << "	[2] Shell Sort" << endl;
	cout << "	[3] Selection Sort" << endl;
	cout << endl;

	cout << "Mode: ";
	cin >> mode;
	cout << endl;

	cout << "Array Size: ";
	cin >> size;
	cout << endl;
	if (mode == 2) { result[0] = size; } //special case for shell

	cout << "Instructions:" << endl;
	cout << endl;
	cout << "	[S] Step (Hold for Slow)" << endl;
	cout << "	[T] Turbo On" << endl;
	cout << "	[O] Turbo Off" << endl;
	cout << "	[L] Guideline On" << endl;
	cout << "	[K] Guideline Off" << endl;
	cout << "	[R] Reset" << endl;
	cout << endl;
	int input;
	cout << "Enter array entries between: -" << size << " and " << size << "" << endl;
	for (int i = 0; i < size; i++) {
		cin >> input;
		arr.push_back(input);
	}

}


void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw state of array

	glColor3d(0.0, 1.0, 0.0);
	glPointSize(0.15);
	if (size <= 500) { glPointSize(0.5); }
	if (size <= 100) { glPointSize(1.0); } //deflate point size until we hit something appropriate given the user's input
	if (size <= 50) { glPointSize(2.0); }
	if (size <= 20) { glPointSize(4.0); }
	if (size <= 10) { glPointSize(5.0); }
	glBegin(GL_POINTS);
	
	//loop to draw dots
	double modifier;
	if (size < 20) { modifier = 0.95; }
	else { modifier = 1.75; }
	for (double i = 0.0; i < arr.size(); i++) {
		double y = modifier*(double(arr[int(i)])) / size; //normalize y values against array size
		double x = 1.75*(i / size) - 0.9;

		glVertex2d(x, y);
	} 

	glEnd(); 

	if (lines) {
		glBegin(GL_LINES);

		if (mode == 1) { //3rd line for bubble sort
			glColor3d(1.0, 0.0, 0.0);
			glVertex2d(1.75*double(result[1] - 1) / size - 0.9, -1.0);
			glVertex2d(1.75*double(result[1] - 1) / size - 0.9, 1.0);
		}
		if (mode == 2) { // main index line for shell sort
			glColor3d(1.0, 0.0, 0.0);
			glVertex2d(1.75*double(result[2]) / size - 0.9, -1.0);
			glVertex2d(1.75*double(result[2]) / size - 0.9, 1.0);
		}
		if (mode != 2) {
			glColor3d(1.0, 1.0, 1.0); //main index line
			glVertex2d(1.75*double(result[0]) / size - 0.9, -1.0);
			glVertex2d(1.75*double(result[0]) / size - 0.9, 1.0);
		}

		glColor3d(1.0, 1.0, 0.0); //sub index line
		glVertex2d(1.75*double(result[1]) / size - 0.9, -1.0);
		glVertex2d(1.75*double(result[1]) / size - 0.9, 1.0);


		glEnd();
	}

	if (turbo && (result[0] != -1)) { //with turbo enabled we run the sort/draw as fast as possible
		if (mode == 1) {
			sorter.bubble_step(arr, result[0], result);
		}
		else if (mode == 0) {
			sorter.insert_step(arr, result[0], result);
		}
		else if (mode == 2) {
			sorter.shell_step(arr, result[0], result);
		}
		else if (mode == 3) {
			sorter.selection_step(arr, result[0], result);
		}
		count++;
		redraw();
	}
	count++;
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    //redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    //redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
	if (key == 's') {
		if (result[0] != -1) {
			if (mode == 1) {
				sorter.bubble_step(arr, result[0], result);
			}
			else if (mode == 0) {
				sorter.insert_step(arr, result[0], result);
			}
			else if (mode == 2) {
				sorter.shell_step(arr, result[0], result);
			}
			else if (mode == 3) {
				sorter.selection_step(arr, result[0], result);
			}
		}
		redraw();
	}
	if (key == 't') {
		turbo = true;
		redraw();
	}
	if (key == 'o'|| result[0] == -1) {
		turbo = false;
	}
	if (key == 'k') {
		lines = false;
		redraw();
	}
	if (key == 'l') {
		lines = true;;
		redraw();
	}
	if (key == 'r') { //reset. reinitialize all variables and clear array, get user input
		arr.clear();
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;

		cout << "	Array cleared! " << endl;
		cout << "	Total Operations: " << count << endl;
		cout << endl;
		cout << "	[0] Insertion Sort" << endl;
		cout << "	[1] Bubble Sort" << endl;
		cout << "	[2] Shell Sort" << endl;
		cout << "	[3] Selection Sort" << endl;
		cout << endl;
		cout << "Mode: ";
		cin >> mode;
		cout << endl;
		count = 0;
		cout << "Array Size: ";
		cin >> size;
		cout << endl;
		if (mode == 2) { result[0] = size; } //special case for shell

		int input;
		cout << "Array's entries between: -" << size << " and " << size << "" << endl;

		for (int i = 0; i < size; i++) {
			cin >> input;
			arr.push_back(input);
		}
		redraw();
	}
}
