#include "pch.h"

#include "gtest/gtest.h"
#include "../RZD 2.0/Piquet.h"
#include "../RZD 2.0/Peregon.h"
TEST(PeregonTest, ConstructorDefault) {
    Peregon peregon;
    ASSERT_EQ(peregon.GetLength(), 0.0);
    ASSERT_EQ(peregon.ToString(), "Перегон: Длина: 0м");
}
TEST(PeregonTest, ConstructorTwoPiquets) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.GetLength(), 87.35);
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м");
}
TEST(PeregonTest, ConstructorTwoDoubles) {
    Peregon peregon(1228.37, 1315.72);
    ASSERT_EQ(peregon.GetLength(), 87.35);
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м");
}
TEST(PeregonTest, AddPiquet) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    peregon.AddPiquet(Piquet(12, 50.0));
    ASSERT_EQ(peregon.GetLength(), 121.68);
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК12+50 ПК13+15.72 Длина: 121.68м");
}
TEST(PeregonTest, GetLength) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.GetLength(), 87.35);
}
TEST(PeregonTest, GetLengthWithNonMeasuredPiquets) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    peregon.AddPiquet(Piquet(1228.37)); // Нестандартный пикет
    ASSERT_EQ(peregon.GetLength(), 207.35);
}
TEST(PeregonTest, ToString) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м");
}
TEST(PeregonTest, ReadFromInput) {
    Peregon peregon;
    std::stringstream ss;
    ss << "12 28.37\n13 15.72\n";
    std::cin.rdbuf(ss.rdbuf());
    peregon.ReadFromInput();
    ASSERT_EQ(peregon.GetLength(), 87.35);
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м");
}
TEST(PiquetTest, ConstructorDefault) {
    Piquet piquet;
    ASSERT_EQ(piquet.Number(), 0);
    ASSERT_EQ(piquet.Shift(), 0.0);
    ASSERT_EQ(piquet.Length(), 100.0);
    ASSERT_TRUE(piquet.IsStandard());
}
TEST(PiquetTest, ConstructorInt) {
    Piquet piquet(12);
    ASSERT_EQ(piquet.Number(), 12);
    ASSERT_EQ(piquet.Shift(), 0.0);
    ASSERT_EQ(piquet.Length(), 100.0);
    ASSERT_TRUE(piquet.IsStandard());
}
TEST(PiquetTest, ConstructorIntDouble) {
    Piquet piquet(12, 28.37);
    ASSERT_EQ(piquet.Number(), 12);
    ASSERT_EQ(piquet.Shift(), 28.37);
    ASSERT_EQ(piquet.Length(), 128.37);
    ASSERT_FALSE(piquet.IsStandard());
}
TEST(PiquetTest, ConstructorDouble) {
    Piquet piquet(1228.37);
    ASSERT_EQ(piquet.Number(), 12);
    ASSERT_EQ(piquet.Shift(), 28.37);
    ASSERT_EQ(piquet.Length(), 1228.37);
    ASSERT_FALSE(piquet.IsStandard());
}
TEST(PiquetTest, ToString) {
    Piquet piquet(12, 28.37);
    ASSERT_EQ(piquet.ToString(), "ПК12+28.37");
}
TEST(PiquetTest, IsMeasured) {
    Piquet piquet(12, 28.37);
    ASSERT_FALSE(piquet.IsMeasured());
}
TEST(PiquetTest, IsMeasuredStandard) {
    Piquet piquet(12);
    ASSERT_TRUE(piquet.IsMeasured());
}
TEST(PiquetTest, Operators) {
    Piquet p1(12, 5.5);
    Piquet p2(12, 5.5);
    Piquet p3(13, 2.0);
    Piquet p4(12, 3.0);
    // Проверка оператора ==
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
    // Проверка оператора !=
    ASSERT_FALSE(p1 != p2);
    ASSERT_TRUE(p1 != p3);
    // Проверка оператора <
    ASSERT_FALSE(p1 < p2);
    ASSERT_TRUE(p1 < p3);
    // Проверка оператора <=
    ASSERT_TRUE(p1 <= p2);
    ASSERT_TRUE(p1 <= p3);
    // Проверка оператора >
    ASSERT_TRUE(p1 > p3);
    ASSERT_FALSE(p1 > p2);
    // Проверка оператора >=
    ASSERT_TRUE(p1 >= p2);
    ASSERT_TRUE(p1 >= p3);
    // Проверка оператора +
    Piquet p5 = p1 + 2.5;
    ASSERT_EQ(p5.Number(), 12);
    ASSERT_EQ(p5.Shift(), 8.0);
    // Проверка оператора -
    Piquet p6 = p1 - 2.5;
    ASSERT_EQ(p6.Number(), 12);
    ASSERT_EQ(p6.Shift(), 3.0);
}

TEST(PiquetTest, OperatorPlus) {
    Piquet piquet(12, 28.37);
    Piquet result = piquet + 10.0;
    ASSERT_EQ(result.Shift(), 38.37);
    ASSERT_EQ(result.Length(), 138.37);
}
TEST(PiquetTest, OperatorMinus) {
    Piquet piquet(12, 28.37);
    Piquet result = piquet - 10.0;
    ASSERT_EQ(result.Shift(), 18.37);
    ASSERT_EQ(result.Length(), 118.37);
}
