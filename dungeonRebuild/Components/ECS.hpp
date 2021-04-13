//
//  ECS.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class Manager;
class GameScene;

using ComponentID = std::size_t;
using Group = std::size_t;

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using componentBitset = std::bitset<maxComponents>;
using GroupBitset = std::bitset<maxGroups>;

using ComponentArray = std::array<Component*, maxComponents>;

inline ComponentID getNewComponentTypeID() {
    static ComponentID lastID = 0u;
    return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept {
    static_assert(std::is_base_of<Component, T>::value, "There is no such component.");
    static ComponentID typeID = getNewComponentTypeID();
    return typeID;
}

class Component {
public:
    Entity *entity;
    
    virtual void init() {};
    virtual void update() {};
    virtual void render() {};
};

class Entity {
    Manager &manager;
    
    bool active = true;
    
    //std::vector<std::unique_ptr<Component>> components;
    std::vector<Component *> components;
    
    ComponentArray componentArray;
    componentBitset componentBitset;
    GroupBitset groupBitset;
    
public:
    GameScene *scene;
    
    Entity(Manager &mManager, GameScene *sc) : manager(mManager), scene(sc) {}
    
    void update();
    void render();
    
    bool isActive() const;
    void destroy();
    
    bool hasGroup(Group mGroup);
    void addGroup(Group mGroup);
    void delGroup(Group mGroup);
    
    template <typename T> bool hasComponent() const {
        return componentBitset[static_cast<size_t>(getComponentTypeID<T>())];
    }
    
    template <typename T, typename ... TArgs>
    T& addComponent(TArgs&&... mArgs) {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        
        //std::unique_ptr<Component> uPtr { c };
        //components.emplace_back(std::move(uPtr));
        components.emplace_back(c);
        
        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;
        
        c->init();
        return *c;
    }
    
    template <typename T> T& getComponent() const {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager {
    //std::vector<std::unique_ptr<Entity>> entities;
    std::vector<Entity *> entities;
    std::array<std::vector<Entity *>, maxGroups> groupedEntities;
    
public:    
    void update();
    void render();
    void refresh();
    
    Entity& addEntity(GameScene *sc);
    Entity& addEntity(GameScene *sc, Group mGroup);
    void addEntity(Entity *mEntity, Group mGroup);
    std::vector<Entity*> &getGroup(Group mGroup);
};

#endif /* ECS_hpp */
