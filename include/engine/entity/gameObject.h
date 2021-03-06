#pragma once

#include <vector>
#include <common/tree.h>
#include <engine/component/transform.h>
#include <memory>
#include <cereal/cereal.hpp>
#include "../../preprocessor.h"
namespace reboot {
    class Component;
    class Renderer;
    class Transform;

    class REBOOT_API GameObject {
    public:
        const char *m_Name;
        Transform *transform;
        Renderer *renderer;

    private:
        Tree<GameObject*> *node;
        bool m_IsActive;
        std::vector<Component *> components;
        int layer;
        unsigned int tag;

    public:
        GameObject(const char *name);

        GameObject() : GameObject("GameObject") {
        }

        template <class Archive>
        void serialize( Archive & ar )
        {
            ar(std::string((m_Name)));
        }

        ~GameObject();
        template<typename T>
        T *getComponent();

        GameObject *getChildAt(unsigned ID) {
            return node->getItem(ID);
        }

        void addChild(GameObject *g) {
            node->addChild(g);
            g->node = node->children[node->children.size()-1];
        }

        GameObject *parent() {
            return node->parent->item;
        }

        void removeChildAt(unsigned ID) {
            node->removeItem(ID);
        }

        Component *getComponentAt(unsigned int index);

        void addComponent(Component *component);

        bool isActive() { return m_IsActive; }


        virtual void Update();
    };
}