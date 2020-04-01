#ifndef ITEM_UPDATERS_H_
#define ITEM_UPDATERS_H_

#include "GildedRose.h"

class DefaultItemUpdater: public ItemUpdater
{
public:
    ~DefaultItemUpdater() {};
    void updateItem(Item& item) override;
};

class OldAlcoholItemUpdater : public DefaultItemUpdater
{
public:
    ~OldAlcoholItemUpdater() {};
    void updateItem(Item& item) override;
}

class TimelessItemUpdater : public DefaultItemUpdater
{
public:
    ~TimelessItemUpdater() {};
    void updateItem(Item& item) override;
}

#endif