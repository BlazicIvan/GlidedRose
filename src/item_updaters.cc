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

void IncreasingQualityItemUpdater::updateItem(Item& item)
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

void BackStagePassesItemUpdater::updateItem(Item& item)
{
    item.sellIn -= 1;

    if (item.sellIn <= 0)
    {
        if (item.quality != 0)
            item.quality = 0;
        return;
    }

    if (item.quality == 50)
      return; // nothing to update if over 50

    item.quality += 1;

    if (item.sellIn <= 10)
    {
        item.quality += 1;  //quality increases by 2 for <= 10 days

        if (item.sellIn <= 5)
        {
            item.quality += 1; // quality increases by 3 for <= 5 days
        }
    }

    // check if item quality increased over 50
    if (item.quality > 50)
    {
      item.quality = 50;
    }
}
