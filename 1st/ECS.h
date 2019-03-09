#pragma once
#include<vector>
#include<memory>
#include<algorithm>
#include<bitset>
#include<array>

//ÉNÉâÉXçÏê¨
class Component;
class Entity;

//**
//*std::size_t can store the maximum size of 
//*a theoretically possible object of any type (including array).
//*std::size_t is commonly used for array indexing and loop counting.
//**
using ComponentID = std::size_t; 

inline ComponentID getComponentID()
{
	static ComponentID lastID = 0; 
	return lastID++;
}

template<typename T> inline ComponentID getComponentID() noexcept
{
	static ComponentID typeID = getComponentID();
	return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
//compare if it already in component or not
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;
	virtual void Init(){}
	virtual void Update(){}
	virtual void Render(){}
	

	virtual ~Component(){}

};
class Entity
{
private:
	//track if this entity active or not
	bool active = true;
	//use unique_ptr instead of pointer to allocate and deallocate memory
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
public:
	void Update()
	{
		for (auto& c : components) c->Update();
		for (auto& c : components) c->Render();
	}
	void Render() {}
	bool isActive()const { return active; }
	void Destroy() { active = false; }

	template<typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentID<T>];
	}
	template<typename T, typename...TArgs>
	T& add