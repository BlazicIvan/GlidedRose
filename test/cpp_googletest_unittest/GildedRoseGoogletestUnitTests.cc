#include <gtest/gtest.h>
#include "GildedRose.h"
#include "item_updaters.h"

TEST(GildedRoseTest, Foo) {
    std::vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    DefaultItemUpdater defaultUpdater = DefaultItemUpdater();
    GildedRose app(items, defaultUpdater);
    app.updateQuality();
    
    std::vector<Item>& appItems = app.getAllItems();
    EXPECT_EQ("Foo", appItems[0].name);
}
