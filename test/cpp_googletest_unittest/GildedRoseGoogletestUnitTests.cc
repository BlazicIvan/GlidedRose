#include <gtest/gtest.h>
#include "GildedRose.h"
#include "item_updaters.h"

TEST(GildedRoseTest, Foo) {
    std::vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
}

TEST(GildedRoseTest, BackStagePassesQuality50)
{
    //arrange
    Item backstagePasses("backstagePasses", 3, 50);
    TicketQualityUpdater testUpdater;

    //act
    testUpdater.updateItem(backstagePasses);

    EXPECT_EQ(50, backstagePasses.quality);
}

TEST(GildedRoseTest, BackStagePassesSellInLessThan5)
{
    //arrange
    Item backstagePasses("backstagePasses", 3, 3);
    TicketQualityUpdater testUpdater;

    //act
    testUpdater.updateItem(backstagePasses);

    EXPECT_EQ(6, backstagePasses.quality);
}

TEST(GildedRoseTest, BackStagePassesSellInLessThan10MoreThan5)
{
    //arrange
    Item backstagePasses("backstagePasses", 7, 3);
    TicketQualityUpdater testUpdater;

    //act
    testUpdater.updateItem(backstagePasses);

    EXPECT_EQ(5, backstagePasses.quality);
}


TEST(GildedRoseTest, BackStagePassesSellIn0)
{
    //arrange
    Item backstagePasses("backstagePasses", 0, 3);
    TicketQualityUpdater testUpdater;

    //act
    testUpdater.updateItem(backstagePasses);

    EXPECT_EQ(0, backstagePasses.quality);
}

TEST(GildedRoseTest, BackStagePassesSellInLessThan0)
{
    //arrange
    Item backstagePasses("backstagePasses", -2, 3);
    TicketQualityUpdater testUpdater;

    //act
    testUpdater.updateItem(backstagePasses);

    EXPECT_EQ(0, backstagePasses.quality);
}

TEST(GildedRoseTest, BackStagePassesQualityOver50)
{
    //arrange
    Item backstagePasses("backstagePasses", 3, 49);
    TicketQualityUpdater testUpdater;

    //act
    testUpdater.updateItem(backstagePasses);

    EXPECT_EQ(50, backstagePasses.quality);
}
