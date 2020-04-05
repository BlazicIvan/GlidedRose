#ifndef ITEM_UPDATERS_H_
#define ITEM_UPDATERS_H_

#include "GildedRose.h"

class DefaultItemUpdater: public ItemUpdater
{
public:
    ~DefaultItemUpdater() {};
    void updateItem(Item& item) override;
};

class IncreasingQualityItemUpdater : public DefaultItemUpdater
{
public:
    ~IncreasingQualityItemUpdater() {};
    void updateItem(Item& item) override;
};

class TimelessItemUpdater : public DefaultItemUpdater
{
public:
    ~TimelessItemUpdater() {};
    void updateItem(Item& item) override;
};

class BackStagePassesItemUpdater : public DefaultItemUpdater
{
public:
    ~BackStagePassesItemUpdater() {};
    void updateItem(Item& item) override;
};

#endif
