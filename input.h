#ifndef INPUT_H
#define INPUT_H

#define DOWN 1
#define UP 0

#include <GL/glut.h>

void mouse_motion (int x, int y);
void mouse_func (int button, int state, int x, int y);
void key_down (unsigned char key, int x, int y);
void key_up (unsigned char key, int x, int y);
void spec_key_down (int key, int x, int y);
void spec_key_up (int key, int x, int y);
void input_update (void);
void input_disable (void);

#endif