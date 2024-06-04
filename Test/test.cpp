#include "pch.h"

#include "gtest/gtest.h"
#include "RZD 2.0/Peregon.h"
#include "RZD 2.0/Piquet.h"
TEST(PeregonTest, ConstructorDefault) {
    Peregon peregon;
    ASSERT_EQ(peregon.GetLength(), 0.0);
    ASSERT_EQ(peregon.ToString(), "�������: �����: 0�");
}
TEST(PeregonTest, ConstructorTwoPiquets) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.GetLength(), 87.35);
    ASSERT_EQ(peregon.ToString(), "�������: ��12+28.37 ��13+15.72 �����: 87.35�");
}
TEST(PeregonTest, ConstructorTwoDoubles) {
    Peregon peregon(1228.37, 1315.72);
    ASSERT_EQ(peregon.GetLength(), 87.35);
    ASSERT_EQ(peregon.ToString(), "�������: ��12+28.37 ��13+15.72 �����: 87.35�");
}
TEST(PeregonTest, AddPiquet) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    peregon.AddPiquet(Piquet(12, 50.0));
    ASSERT_EQ(peregon.GetLength(), 121.68);
    ASSERT_EQ(peregon.ToString(), "�������: ��12+28.37 ��12+50 ��13+15.72 �����: 121.68�");
}
TEST(PeregonTest, GetLength) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.GetLength(), 87.35);
}
TEST(PeregonTest, GetLengthWithNonMeasuredPiquets) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    peregon.AddPiquet(Piquet(1228.37)); // ������������� �����
    ASSERT_EQ(peregon.GetLength(), 207.35);
}
TEST(PeregonTest, ToString) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.ToString(), "�������: ��12+28.37 ��13+15.72 �����: 87.35�");
}
TEST(PeregonTest, ReadFromInput) {
    Peregon peregon;
    std::stringstream ss;
    ss << "12 28.37\n13 15.72\n";
    std::cin.rdbuf(ss.rdbuf());
    peregon.ReadFromInput();
    ASSERT_EQ(peregon.GetLength(), 87.35);
    ASSERT_EQ(peregon.ToString(), "�������: ��12+28.37 ��13+15.72 �����: 87.35�");
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
    ASSERT_EQ(piquet.ToString(), "��12+28.37");
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
    Piquet piquet1(12, 28.37);
    Piquet piquet2(12, 28.37);
    Piquet piquet3(13, 15.72);
    ASSERT_TRUE(piquet1 == piquet2);
    ASSERT_FALSE(piquet1 == piquet3);
    ASSERT_TRUE(piquet1 != piquet3);
    ASSERT_TRUE(piquet1 < piquet3);
    ASSERT_TRUE(piquet1 <= piquet3);
    ASSERT_TRUE(piquet3 > piquet1);
    ASSERT_TRUE(piquet3 >= piquet1);
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