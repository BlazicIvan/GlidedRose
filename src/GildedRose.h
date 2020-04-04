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
    std::map<std::string, ItemUpdater*> mUpdaters;

public:
    std::vector<Item> & items;
    GildedRose(std::vector<Item> & items);
    ~GildedRose();
    
    void updateQuality();
};

#endif