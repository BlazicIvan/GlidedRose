#include <gtest/gtest.h>
#include "GildedRose.h"
#include "item_updaters.h"

TEST(GildedRoseTest, Foo) {
    std::vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    
    EXPECT_EQ("Aaa", app.items[0].name);
}
