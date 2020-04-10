#include "GildedRose.h"
#include "item_updaters.h"


GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{
    mUpdaters[""] = new DefaultItemUpdater();
    mUpdaters["Aged Brie"] = new IncreasingQualityItemUpdater();
    mUpdaters["Sulfuras"] = new TimelessItemUpdater();
    mUpdaters["Backstage passes"] = new TicketQualityUpdater();
    mUpdaters["Conjured"] = new FastQualityDropItemUpdater();
}

GildedRose::~GildedRose()
{
    for(auto &mapItem : mUpdaters)
    {
        delete mapItem.second;
    }
}
   
void GildedRose::updateQuality() 
{
    for(Item& item : items)
    {
        const std::string itemName = item.name;
        auto pos = mUpdaters.find(itemName);

        if(pos != mUpdaters.end())
        {
            pos->second->updateItem(item);
        }
        else
        {
            mUpdaters[""]->updateItem(item);
        }
    }
}
