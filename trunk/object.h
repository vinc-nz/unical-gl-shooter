
#ifndef OBJECT_H
#define OBJECT_H

#define WALL_HEIGHT 10

enum ObjectType
{
	TYPE_WALL,
	TYPE_BULLET,
	TYPE_TURRET,
	TYPE_FLOOR,
	TYPE_TOP,
	TYPE_CHARACTER,
	TYPE_CUBE,
	TYPE_WINDOW,
	TYPE_SPHERE,
	TYPE_BLOOD
};

/** struct that represents an object of the scene...
 */
typedef struct object_t {
	
	float pos_x, pos_y, pos_z; 		/* position */
	float 	min_x, max_x, 
			min_y, max_y, 
			min_z, max_z; 			/* bounds */

	double rot_x, rot_y; 			/* direction */
	float vel; 						/* movement's vel */
	int type; 						/* obj type 	*/
	int energy; 					/* current energy */
	int score;						/* current score (just for player) */
	int collides;					/* true if obj can collides, default 0 */
	int transparent;				/* true if transparent, default 0 */
	
	double curr_time, last_time;	/* useful for timer-dependent functions (e.g. shoot) */

	void *data;						/* something (e.g. another object) that this object needs */

	/** draw this object */
	void (*display) (struct object_t *this);
	/** update this object */
	void (*update) (struct object_t *this);
	/** what to do when this object collides with obj? */
	void (*onCollision) (struct object_t *this, struct object_t *obj);
	
} object_t;

/** return true if this object collides with obj */
int hasCollision (object_t *this, object_t *obj);

/** create functions */
object_t *newObject (float min_x, float min_y, float min_z);
object_t *newCharacter (int pos_x, int pos_y, int pos_z);
object_t *newWeapon (float pos_x, float pos_y, float pos_z);
object_t *newWall (float min_x, float max_x, float min_z, float max_z);
object_t *newBullet (struct object_t *owner);
object_t *newFloor (float max_x, float max_y, float max_z);
object_t *newTop (float max_x, float max_y, float max_z);
object_t *newTurret (float min_x, float min_z);
object_t *newCube (float min_x, float min_z);
object_t *newExplosion (float *pos, int p, int d, int lifetime, float scale, float *color, double speed);
object_t *newSolarSystem (int pos_x, int pos_y, int pos_z);
#endif