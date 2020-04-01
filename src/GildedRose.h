#ifndef GLIDED_ROSE_H_
#define GLIDED_ROSE_H_

#include <string>
#include <vector>
#include <map>


class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class ItemUpdater
{
public:
    virtual ~ItemUpdater() {};

    virtual void updateItem(Item& item) = 0;
};

class GildedRose
{
private:
    std::vector<Item> & items;
    std::map<std::string, ItemUpdater&> updaters;

public:

    GildedRose(std::vector<Item> & items, ItemUpdater& defaultUpdater);

    void addExceptionalUpdater(std::string name, ItemUpdater& updater);

    std::vector<Item>& getAllItems();
    
    void updateQuality();
};

#endif