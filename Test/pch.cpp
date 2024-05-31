#include "gtest/gtest.h"
#include "../Library/IntegerCollection.h"

TEST(IntegerCollectionTest, BasicOperations) {
    IntegerCollection collection = { 5, 2, 8, 1, 9 };

    // Проверка начального состояния
    EXPECT_EQ(collection.toString(), "5 2 8 1 9 ");

    // Проверка вставки элемента
    collection << 10;
    EXPECT_EQ(collection.toString(), "5 2 8 1 9 10 ");

    // Проверка удаления последнего элемента
    collection >> 10;
    EXPECT_EQ(collection.toString(), "5 2 8 1 9 ");

    // Проверка поиска элемента с максимальным приоритетом
    EXPECT_EQ(collection.findMaxPriorityElement(), 9);
}