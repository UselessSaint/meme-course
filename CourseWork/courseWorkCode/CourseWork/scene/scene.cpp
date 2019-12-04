#include "scene.h"

Scene::Scene()
{

}

void Scene::addObject(std::shared_ptr<Object> obj)
{
	_objects.push_back(obj);
}

void Scene::removeObject(int id)
{
	if (id <= _objects.size())
	{
		_objects.erase(_objects.begin() + id);
	}
}

void Scene::addLight(std::shared_ptr<Light> lt)
{
	_lights.push_back(lt);
}

void Scene::removeLight(int id)
{
	if (id <= _lights.size())
	{
		_lights.erase(_lights.begin() + id);
	}
}

std::vector<std::shared_ptr<Object>> Scene::getObjects()
{
	return _objects;
}

std::vector<std::shared_ptr<Light>> Scene::getLights()
{
	return _lights;
}
