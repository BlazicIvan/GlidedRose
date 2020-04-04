#include "item_updaters.h"

void DefaultItemUpdater::updateItem(Item& item)
{
    if (item.quality > 0)
    {
        item.quality -= 1;
        item.sellIn -= 1;
        if (item.sellIn < 0 && item.quality > 0)
        {
            item.quality -= 1;
        }
    }
}

void OldAlcoholItemUpdater::updateItem(Item& item)
{
    if (item.quality < 50)
    {
        item.quality += 1;
        item.sellIn -= 1;
        if (item.sellIn < 0 && item.quality < 50)
        {
            item.quality += 1;
        }
    }
}

void TimelessItemUpdater::updateItem(Item& item)
{

}