#include <gtest/gtest.h>
#include "list.h"
#include "list.cpp"
#include <string> // for string class

using namespace std;

TEST(ListTest, TestInitialLength) {
    List<string> list;
    ASSERT_EQ(list.length(), 0);
}

TEST(ListTest, TestAppendCount) {
    List<string> list;
    string g = "Some text";
    list.append(&g);
    ASSERT_EQ(list.length(), 1);
}

TEST(ListTest, TestAppendRepeatedCount) {
    List<string> list;
    string g = "Some text";
    list.append(&g);
    list.append(&g);
    list.append(&g);
    ASSERT_EQ(list.length(), 3);
}

TEST(ListTest, TestAppendValue) {
    List<string> list;
    string g = "Some text";
    list.append(&g);
    ASSERT_EQ(list[0], g);
}

TEST(ListTest, TestPrependCount) {
    List<string> list;
    string g = "Some text";
    list.prepend(&g);
    ASSERT_EQ(list.length(), 1);
}

TEST(ListTest, TestPrependRepeatedCount) {
    List<string> list;
    string g = "Some text";
    list.prepend(&g);
    list.prepend(&g);
    list.prepend(&g);
    ASSERT_EQ(list.length(), 3);
}

TEST(ListTest, TestPrependValue) {
    List<string> list;
    string g = "Some text";
    list.prepend(&g);
    ASSERT_EQ(list[0], g);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
