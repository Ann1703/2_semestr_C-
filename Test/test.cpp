#include "pch.h"

#include "gtest/gtest.h"
#include "../RZD 2.0/Piquet.h"
#include "../RZD 2.0/Peregon.h"

// Тест для проверки конструктора по умолчанию класса Peregon
TEST(PeregonTest, ConstructorDefault) {
    Peregon peregon;
    ASSERT_EQ(peregon.GetLength(), 0.0); // Проверяем, что длина перегона равна 0
    ASSERT_EQ(peregon.ToString(), "Перегон: Длина: 0м"); // Проверяем, что строковое представление перегона корректно
}

// Тест для проверки конструктора класса Peregon с двумя пикетами
TEST(PeregonTest, ConstructorTwoPiquets) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.GetLength(), 87.35); // Проверяем, что длина перегона рассчитана правильно
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м"); // Проверяем, что строковое представление перегона корректно
}

// Тест для проверки конструктора класса Peregon с двумя значениями типа double
TEST(PeregonTest, ConstructorTwoDoubles) {
    Peregon peregon(1228.37, 1315.72);
    ASSERT_EQ(peregon.GetLength(), 87.35); // Проверяем, что длина перегона рассчитана правильно
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м"); // Проверяем, что строковое представление перегона корректно
}

// Тест для проверки метода AddPiquet класса Peregon
TEST(PeregonTest, AddPiquet) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    peregon.AddPiquet(Piquet(12, 50.0)); // Добавляем новый пикет
    ASSERT_EQ(peregon.GetLength(), 121.68); // Проверяем, что длина перегона рассчитана правильно
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК12+50 ПК13+15.72 Длина: 121.68м"); // Проверяем, что строковое представление перегона корректно
}

// Тест для проверки метода GetLength класса Peregon
TEST(PeregonTest, GetLength) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.GetLength(), 87.35); // Проверяем, что длина перегона рассчитана правильно
}

// Тест для проверки метода GetLength класса Peregon с неизмеренными пикетами
TEST(PeregonTest, GetLengthWithNonMeasuredPiquets) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    peregon.AddPiquet(Piquet(1228.37)); // Добавляем нестандартный пикет
    ASSERT_EQ(peregon.GetLength(), 207.35); // Проверяем, что длина перегона рассчитана правильно
}

// Тест для проверки метода ToString класса Peregon
TEST(PeregonTest, ToString) {
    Peregon peregon(Piquet(12, 28.37), Piquet(13, 15.72));
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м"); // Проверяем, что строковое представление перегона корректно
}

// Тест для проверки метода ReadFromInput класса Peregon
TEST(PeregonTest, ReadFromInput) {
    Peregon peregon;
    std::stringstream ss;
    ss << "12 28.37\n13 15.72\n";
    std::cin.rdbuf(ss.rdbuf());
    peregon.ReadFromInput();
    ASSERT_EQ(peregon.GetLength(), 87.35); // Проверяем, что длина перегона рассчитана правильно
    ASSERT_EQ(peregon.ToString(), "Перегон: ПК12+28.37 ПК13+15.72 Длина: 87.35м"); // Проверяем, что строковое представление перегона корректно
}

// Тест для проверки конструктора по умолчанию класса Piquet
TEST(PiquetTest, ConstructorDefault) {
    Piquet piquet;
    ASSERT_EQ(piquet.Number(), 0); // Проверяем, что номер пикета равен 0
    ASSERT_EQ(piquet.Shift(), 0.0); // Проверяем, что сдвиг пикета равен 0
    ASSERT_EQ(piquet.Length(), 100.0); // Проверяем, что длина пикета равна 100
    ASSERT_TRUE(piquet.IsStandard()); // Проверяем, что пикет является стандартным
}

// Тест для проверки конструктора класса Piquet с параметром типа int
TEST(PiquetTest, ConstructorInt) {
    Piquet piquet(12);
    ASSERT_EQ(piquet.Number(), 12); // Проверяем, что номер пикета равен 12
    ASSERT_EQ(piquet.Shift(), 0.0); // Проверяем, что сдвиг пикета равен 0
    ASSERT_EQ(piquet.Length(), 100.0); // Проверяем, что длина пикета равна 100
    ASSERT_TRUE(piquet.IsStandard()); // Проверяем, что пикет является стандартным
}

// Тест для проверки конструктора класса Piquet с параметрами типа int и double
TEST(PiquetTest, ConstructorIntDouble) {
    Piquet piquet(12, 28.37);
    ASSERT_EQ(piquet.Number(), 12); // Проверяем, что номер пикета равен 12
    ASSERT_EQ(piquet.Shift(), 28.37); // Проверяем, что сдвиг пикета равен 28.37
    ASSERT_EQ(piquet.Length(), 128.37); // Проверяем, что длина пикета равна 128.37
    ASSERT_FALSE(piquet.IsStandard()); // Проверяем, что пикет не является стандартным
}

// Тест для проверки конструктора класса Piquet с параметром типа double
TEST(PiquetTest, ConstructorDouble) {
    Piquet piquet(1228.37);
    ASSERT_EQ(piquet.Number(), 12); // Проверяем, что номер пикета равен 12
    ASSERT_EQ(piquet.Shift(), 28.37); // Проверяем, что сдвиг пикета равен 28.37
    ASSERT_EQ(piquet.Length(), 1228.37); // Проверяем, что длина пикета равна 1228.37
    ASSERT_FALSE(piquet.IsStandard()); // Проверяем, что пикет не является стандартным
}

// Тест для проверки метода ToString класса Piquet
TEST(PiquetTest, ToString) {
    Piquet piquet(12, 28.37);
    ASSERT_EQ(piquet.ToString(), "ПК12+28.37"); // Проверяем, что строковое представление пикета корректно
}

// Тест для проверки метода IsMeasured класса Piquet
TEST(PiquetTest, IsMeasured) {
    Piquet piquet(12, 28.37);
    ASSERT_FALSE(piquet.IsMeasured()); // Проверяем, что пикет неизмерен
}

// Тест для проверки метода IsMeasured класса Piquet с стандартным пикетом
TEST(PiquetTest, IsMeasuredStandard) {
    Piquet piquet(12);
    ASSERT_TRUE(piquet.IsMeasured()); // Проверяем, что пикет измерен
}

// Тест для проверки операторов класса Piquet
TEST(PiquetTest, Operators) {
    Piquet p1(12, 5.5);
    Piquet p2(12, 5.5);
    Piquet p3(13, 2.0);
    Piquet p4(12, 3.0);
    // Проверка оператора ==
    ASSERT_TRUE(p1 == p2); // Проверяем, что p1 равен p2
    ASSERT_FALSE(p1 == p3); // Проверяем, что p1 не равен p3
    // Проверка оператора !=
    ASSERT_FALSE(p1 != p2); // Проверяем, что p1 не не равен p2
    ASSERT_TRUE(p1 != p3); // Проверяем, что p1 не равен p3
    // Проверка оператора <
    ASSERT_FALSE(p1 < p2); // Проверяем, что p1 не меньше p2
    ASSERT_TRUE(p1 < p3); // Проверяем, что p1 меньше p3
    // Проверка оператора <=
    ASSERT_TRUE(p1 <= p2); // Проверяем, что p1 меньше или равен p2
    ASSERT_TRUE(p1 <= p3); // Проверяем, что p1 меньше или равен p3
    // Проверка оператора >
    ASSERT_TRUE(p1 > p3); // Проверяем, что p1 больше p3
    ASSERT_FALSE(p1 > p2); // Проверяем, что p1 не больше p2
    // Проверка оператора >=
    ASSERT_TRUE(p1 >= p2); // Проверяем, что p1 больше или равен p2
    ASSERT_TRUE(p1 >= p3); // Проверяем, что p1 больше или равен p3
    // Проверка оператора +
    Piquet p5 = p1 + 2.5;
    ASSERT_EQ(p5.Number(), 12); // Проверяем, что номер пикета равен 12
    ASSERT_EQ(p5.Shift(), 8.0); // Проверяем, что сдвиг пикета равен 8.0
    // Проверка оператора -
    Piquet p6 = p1 - 2.5;
    ASSERT_EQ(p6.Number(), 12); // Проверяем, что номер пикета равен 12
    ASSERT_EQ(p6.Shift(), 3.0); // Проверяем, что сдвиг пикета равен 3.0
}

// Тест для проверки оператора + класса Piquet
TEST(PiquetTest, OperatorPlus) {
    Piquet piquet(12, 28.37);
    Piquet result = piquet + 10.0;
    ASSERT_EQ(result.Shift(), 38.37); // Проверяем, что сдвиг рассчитан правильно
    ASSERT_EQ(result.Length(), 138.37); // Проверяем, что длина рассчитана правильно
}

// Тест для проверки оператора - класса Piquet
TEST(PiquetTest, OperatorMinus) {
    Piquet piquet(12, 28.37);
    Piquet result = piquet - 10.0;
    ASSERT_EQ(result.Shift(), 18.37); // Проверяем, что сдвиг рассчитан правильно
    ASSERT_EQ(result.Length(), 118.37); // Проверяем, что длина рассчитана правильно
}
