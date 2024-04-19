#include "CppUTest/TestHarness.h"
#include "app/hangmanDrawer/HangMan.h"

#include <string>

TEST_GROUP(HangmanTestsGroup)
{
    HangmanDrawer* hangmanDrawer = nullptr;

    void setup()
    {
        hangmanDrawer = new HangmanDrawer();
    }

    void teardown()
    {
        delete hangmanDrawer;
    }
};

TEST(HangmanTestsGroup, HangmanTest)
{
    CHECK_EQUAL(0, hangmanDrawer->getCurrentPart());
    CHECK_FALSE(hangmanDrawer->isFullyDrawn());

    hangmanDrawer->fail();
    CHECK_EQUAL(1, hangmanDrawer->getCurrentPart());
    CHECK_FALSE(hangmanDrawer->isFullyDrawn());
}

TEST(HangmanTestsGroup, HangmanFullDrawnTest)
{
    CHECK_EQUAL(0, hangmanDrawer->getCurrentPart());
    CHECK_FALSE(hangmanDrawer->isFullyDrawn());

    for (size_t i = 0; i < hangmanDrawer->getHangmanParts().size(); i++)
    {
        hangmanDrawer->fail();
    }

    CHECK_EQUAL(hangmanDrawer->getHangmanParts().size(), hangmanDrawer->getCurrentPart());
    CHECK_TRUE(hangmanDrawer->isFullyDrawn());
}