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

TEST(GildedRoseTest, DefaultItemQuality0)
{
    Item defaultItem("default", 10, 0);
    DefaultItemUpdater testUpdater;

    testUpdater.updateItem(defaultItem);
    EXPECT_EQ(0, defaultItem.quality);
}

TEST(GildedRoseTest, DefaultItemQualityGreaterThan0)
{
    Item defaultItem("default", 10, 15);
    DefaultItemUpdater testUpdater;

    testUpdater.updateItem(defaultItem);
    EXPECT_EQ(14, defaultItem.quality);
}

TEST(GildedRoseTest, DefaultItemSellInLessThan0)
{
    Item defaultItem("default", -2, 20);
    DefaultItemUpdater testUpdater;

    testUpdater.updateItem(defaultItem);
    EXPECT_EQ(18, defaultItem.quality);
}

TEST(GildedRoseTest, DefaultItemSellInLessThan0Quality1)
{
    Item defaultItem("default", -5, 1);
    DefaultItemUpdater testUpdater;

    testUpdater.updateItem(defaultItem);
    EXPECT_EQ(0, defaultItem.quality);
}

TEST(GildedRoseTest, IncreasingQualityItemQualityLestThan50)
{
    Item increasingQualityItem("agedBrie", 10, 20);
    IncreasingQualityItemUpdater testUpdater;

    testUpdater.updateItem(increasingQualityItem);
    EXPECT_EQ(21, increasingQualityItem.quality);
}

TEST(GildedRoseTest, IncreasingQualityItemQuality50)
{
    Item increasingQualityItem("agedBrie", 10, 50);
    IncreasingQualityItemUpdater testUpdater;

    testUpdater.updateItem(increasingQualityItem);
    EXPECT_EQ(50, increasingQualityItem.quality);
}

TEST(GildedRoseTest, IncreasingQualityItemSellInLessThan0)
{
    Item increasingQualityItem("agedBrie", -3, 20);
    IncreasingQualityItemUpdater testUpdater;

    testUpdater.updateItem(increasingQualityItem);
    EXPECT_EQ(22, increasingQualityItem.quality);
}

TEST(GildedRoseTest, IncreasingQualityItemSellInLessThan0Quality49)
{
    Item increasingQualityItem("agedBrie", -4, 49);
    IncreasingQualityItemUpdater testUpdater;

    testUpdater.updateItem(increasingQualityItem);
    EXPECT_EQ(50, increasingQualityItem.quality);
}

TEST(GildedRoseTest, TimelessItemQualityLessThan50)
{
    //arrange
    Item timelessItem("sulfuras", 10, 30);
    TimelessItemUpdater testUpdater;

    //act
    testUpdater.updateItem(timelessItem);
    EXPECT_EQ(30, timelessItem.quality);
    EXPECT_EQ(10, timelessItem.sellIn);
}

TEST(GildedRoseTest, TimelessItemQuality50)
{
    //arrange
    Item timelessItem("sulfuras", 20, 50);
    TimelessItemUpdater testUpdater;

    //act
    testUpdater.updateItem(timelessItem);
    EXPECT_EQ(50, timelessItem.quality);
    EXPECT_EQ(20, timelessItem.sellIn);
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

TEST(GildedRoseTest, FastQualityDropQuality0)
{
    //arrange
    Item fastQualityDropItem("conjured", 3, 0);
    FastQualityDropItemUpdater testUpdater;

    //act
    testUpdater.updateItem(fastQualityDropItem);

    EXPECT_EQ(0, fastQualityDropItem.quality);
}

TEST(GildedRoseTest, FastQualityDropQualityGreaterThan0)
{
    //arrange
    Item fastQualityDropItem("conjured", 3, 20);
    FastQualityDropItemUpdater testUpdater;

    //act
    testUpdater.updateItem(fastQualityDropItem);

    EXPECT_EQ(18, fastQualityDropItem.quality);
}

TEST(GildedRoseTest, FastQualityDropSellInLessThan0)
{
    //arrange
    Item fastQualityDropItem("conjured", -3, 20);
    FastQualityDropItemUpdater testUpdater;

    //act
    testUpdater.updateItem(fastQualityDropItem);

    EXPECT_EQ(16, fastQualityDropItem.quality);
}