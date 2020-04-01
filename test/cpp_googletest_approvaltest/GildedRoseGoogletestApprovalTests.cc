// Include header files for test frameworks 
#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

// Include code to be tested
#include "GildedRose.h"
#include "item_updaters.h"

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
        << "name: " << obj.name
        << ", sellIn: " << obj.sellIn
        << ", quality: " << obj.quality;
}

TEST(GildedRoseApprovalTests, VerifyCombinations) {

    std::vector<std::string> names { "Foo" };
    std::vector<int> sellIns { 1 };
    std::vector<int> qualities { 1 };

    auto f = [](std::string name, int sellIn, int quality) {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        DefaultItemUpdater defaultUpdater = DefaultItemUpdater();
        GildedRose app(items, defaultUpdater);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            names, sellIns, qualities);

}
