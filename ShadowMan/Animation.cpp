#include "Animation.h"

void AnimationLight(Object* object, int* object_id, int flame_counts)
{
	object->flame_count += 1.0f;
	switch (*object_id)
	{
	case 0:
		DrawObject(object->x, object->y, 576.0f, 225.0f, 64, 64);
		ChangeTextureId(object, object_id, 30);
		break;
	case 1:
		DrawObject(object->x, object->y, 640.0f, 225.0f, 64, 64);
		ChangeTextureId(object, object_id, 30);
		break;
	case 2:
		DrawObject(object->x, object->y, 704.0f, 225.0f, 64, 64);
		ChangeTextureId(object, object_id, 30);
		break;
	case 3:
		DrawObject(object->x, object->y, 768.0f, 225.0f, 64, 64);
		if (object->flame_count >= flame_counts)
		{
			object->flame_count = 0;
			*object_id = 0;
		}
		break;
	}
}

void AnimationShadowMan(Object* object, int* object_id, int flame_counts)
{
	object->flame_count += 1.0f;
	switch (*object_id)
	{
	case 0:
		DrawObject(object->x, object->y, 0.0f, 225.0f, 64, 64);
		ChangeTextureId(object, object_id, flame_counts);
		break;
	case 1:
		DrawObject(object->x, object->y, 64.0f, 225.0f, 64, 64);
		if (object->flame_count >= flame_counts)
		{
			object->flame_count = 0;
			*object_id = 0;
		}
		break;
	}
}