
default:
	gcc -o game scene.c object.c objectlist.c camera.c input.c hud.c tga.c main.c -lglut -lGL -lGLU	
clean:
	rm game