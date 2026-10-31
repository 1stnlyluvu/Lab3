#include <gtest/gtest.h>

/// Проверяет истинность двойного неравенства a < b < c.
/// Задача Boolean6.
/// Параметры: три целых числа.
/// Результат: true, если a < b и b < c.
bool are_strictly_increasing(int a, int b, int c) {
    return a < b && b < c;
}

/// Проверяет, что все цифры трёхзначного числа различны.
/// Задача Boolean20.
/// Параметр: трёхзначное положительное число.
/// Результат: true, если ни одна пара цифр не совпадает.
bool has_distinct_digits(int number) {
    int hundreds = number / 100;
    int tens = (number / 10) % 10;
    int units = number % 10;

    return hundreds != tens && hundreds != units && tens != units;
}

/// Проверяет, может ли ладья перейти за один ход между двумя разными полями.
/// Задача Boolean36.
/// Параметры: координаты двух полей шахматной доски (от 1 до 8).
/// Результат: true, если поля находятся на одной вертикали или горизонтали.
bool can_rook_move(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2;
}

/// Проверка правильного двойного неравенства.
TEST(Boolean6, IncreasingNumbers) {
    // Arrange
    int a = 1, b = 3, c = 5;

    // Act
    bool result = are_strictly_increasing(a, b, c);

    // Assert
    EXPECT_TRUE(result);
}

/// Проверка равных соседних чисел.
TEST(Boolean6, EqualNumbers) {
    // Arrange
    int a = 2, b = 2, c = 5;

    // Act
    bool result = are_strictly_increasing(a, b, c);

    // Assert
    EXPECT_FALSE(result);
}

/// Проверка неправильного порядка чисел.
TEST(Boolean6, WrongOrder) {
    // Arrange
    int a = 5, b = 3, c = 7;

    // Act
    bool result = are_strictly_increasing(a, b, c);

    // Assert
    EXPECT_FALSE(result);
}

/// Проверка числа с тремя разными цифрами.
TEST(Boolean20, AllDigitsDifferent) {
    // Arrange
    int number = 123;

    // Act
    bool result = has_distinct_digits(number);

    // Assert
    EXPECT_TRUE(result);
}

/// Проверка совпадения цифр сотен и единиц.
TEST(Boolean20, SameHundredsAndUnits) {
    // Arrange
    int number = 121;

    // Act
    bool result = has_distinct_digits(number);

    // Assert
    EXPECT_FALSE(result);
}

/// Проверка совпадения цифр десятков и единиц.
TEST(Boolean20, SameTensAndUnits) {
    // Arrange
    int number = 122;

    // Act
    bool result = has_distinct_digits(number);

    // Assert
    EXPECT_FALSE(result);
}

/// Проверка хода ладьи по горизонтали.
TEST(Boolean36, SameRow) {
    // Arrange
    int x1 = 2, y1 = 4, x2 = 7, y2 = 4;

    // Act
    bool result = can_rook_move(x1, y1, x2, y2);

    // Assert
    EXPECT_TRUE(result);
}

/// Проверка хода ладьи по вертикали.
TEST(Boolean36, SameColumn) {
    // Arrange
    int x1 = 5, y1 = 1, x2 = 5, y2 = 8;

    // Act
    bool result = can_rook_move(x1, y1, x2, y2);

    // Assert
    EXPECT_TRUE(result);
}

/// Проверка невозможного диагонального хода.
TEST(Boolean36, DiagonalMove) {
    // Arrange
    int x1 = 2, y1 = 3, x2 = 4, y2 = 5;

    // Act
    bool result = can_rook_move(x1, y1, x2, y2);

    // Assert
    EXPECT_FALSE(result);
}
