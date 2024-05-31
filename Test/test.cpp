#include "gtest/gtest.h"
#include "../Library/IntegerCollection.h"

TEST(IntegerCollectionTest, BasicOperations) {
    IntegerCollection collection = { 5, 2, 8, 1, 9 };

    
    EXPECT_EQ(collection.toString(), "5 2 8 1 9 ");

    
    collection << 10;
    EXPECT_EQ(collection.toString(), "5 2 8 1 9 10 ");

   
    collection >> 10; 
    EXPECT_EQ(collection.toString(), "5 2 8 1 9 ");

  
    EXPECT_EQ(collection.findMaxPriorityElement(), 9);
}
