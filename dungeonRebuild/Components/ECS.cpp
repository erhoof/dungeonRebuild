//
//  ECS.cpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 09/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#include "ECS.hpp"

// Entity
void Entity::update() {
    for (auto& c: components) c->update();
}

void Entity::render() {
    for (auto& c: components) c->render();
}

bool Entity::isActive() const {
    return active;
}

void Entity::destroy() {
    active = false;
}

bool Entity::hasGroup(Group mGroup) {
    return groupBitset[mGroup];
}

void Entity::addGroup(Group mGroup) {
    groupBitset[mGroup] = true;
    manager.addEntity(this, mGroup);
}

void Entity::delGroup(Group mGroup) {
    groupBitset[mGroup] = false;
}

// Manager
void Manager::update() {
    for (auto& e : entities) if (e->isActive()) e->update();
}

void Manager::render() {
    for (auto& e: entities) e->render();
}

void Manager::refresh () {
    for (auto i(0u); i<maxGroups; i++) {
        auto& v(groupedEntities[i]);
        v.erase(
                std::remove_if(std::begin(v), std::end(v),
                               [i](Entity* mEntity) {
                                   return !mEntity->isActive() || !mEntity->hasGroup(i);
                               }),
                std::end(v));
    }
    
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                  //[](const std::unique_ptr<Entity> &mEntity) {
                                  [](Entity* mEntity) {
                                      return !mEntity->isActive();
                                  }),
                   std::end(entities));
}

void Manager::addEntity(Entity* mEntity, Group mGroup) {
    groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& Manager::getGroup(Group mGroup) {
    return groupedEntities[mGroup];
}

Entity& Manager::addEntity(GameScene *sc) {
    Entity *e = new Entity(*this, sc);
    
    //std::unique_ptr<Entity> uPtr{ e };
    
    //entities.emplace_back(std::move(uPtr));
    entities.emplace_back(e);
    
    return *e;
}

Entity& Manager::addEntity(GameScene *sc, Group mGroup) {
    Entity *e = new Entity(*this, sc);
    e->addGroup(mGroup);
    
    //std::unique_ptr<Entity> uPtr{ e };
    
    //entities.emplace_back(std::move(uPtr));
    entities.emplace_back(e);
    
    return *e;
}
