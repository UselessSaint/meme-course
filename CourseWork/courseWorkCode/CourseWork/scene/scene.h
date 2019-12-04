#ifndef SCENE_H
#define SCENE_H

#include "../objects/object.h"
#include "light.h"

class Scene
{
public:
    Scene();

	void addObject(std::shared_ptr<Object> obj);
	void removeObject(int id);

	void addLight(std::shared_ptr<Light> lt);
	void removeLight(int id);

	std::vector<std::shared_ptr<Object>> getObjects();
	std::vector<std::shared_ptr<Light>> getLights();

private:
	std::vector<std::shared_ptr<Object>> _objects;
	std::vector<std::shared_ptr<Light>> _lights;
};

#endif // SCENE_H
