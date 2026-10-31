#include <gtest/gtest.h>
#include <string>

// IF25

/// Вычисляет функцию по условию задачи If25.
int calculate_piecewise_value(int x) {
    if (x < -2 || x > 2) {
        return 2 * x;
    }
    return -3 * x;
}

/// Проверка числа меньше -2.
TEST(If25, LessThanMinusTwo) {
    // Arrange
    int x = -3;

    // Act
    int result = calculate_piecewise_value(x);

    // Assert
    EXPECT_EQ(result, -6);
}

/// Проверка границы -2.
TEST(If25, AtMinusTwo) {
    // Arrange
    int x = -2;

    // Act
    int result = calculate_piecewise_value(x);

    // Assert
    EXPECT_EQ(result, 6);
}

/// Проверка нуля.
TEST(If25, Zero) {
    // Arrange
    int x = 0;

    // Act
    int result = calculate_piecewise_value(x);

    // Assert
    EXPECT_EQ(result, 0);
}

/// Проверка границы 2.
TEST(If25, AtTwo) {
    // Arrange
    int x = 2;

    // Act
    int result = calculate_piecewise_value(x);

    // Assert
    EXPECT_EQ(result, -6);
}

/// Проверка числа больше 2.
TEST(If25, GreaterThanTwo) {
    // Arrange
    int x = 3;

    // Act
    int result = calculate_piecewise_value(x);

    // Assert
    EXPECT_EQ(result, 6);
}

// IF42
// По условию задачи If29.

/// Определяет знак и четность целого числа.
std::string describe_signed_number(int number) {
    if (number == 0) {
        return "нулевое число";
    }

    std::string sign;

    if (number > 0) {
        sign = "положительное";
    }
    else {
        sign = "отрицательное";
    }

    std::string parity;

    if (number % 2 == 0) {
        parity = "четное";
    }
    else {
        parity = "нечетное";
    }

    return sign + " " + parity + " число";
}

/// Проверка положительного нечетного числа.
TEST(If42, PositiveOdd) {
    // Arrange
    int number = 7;

    // Act
    std::string result = describe_signed_number(number);

    // Assert
    EXPECT_EQ(result, "положительное нечетное число");
}

/// Проверка отрицательного четного числа.
TEST(If42, NegativeEven) {
    // Arrange
    int number = -8;

    // Act
    std::string result = describe_signed_number(number);

    // Assert
    EXPECT_EQ(result, "отрицательное четное число");
}

/// Проверка отрицательного нечетного числа.
TEST(If42, NegativeOdd) {
    // Arrange
    int number = -3;

    // Act
    std::string result = describe_signed_number(number);

    // Assert
    EXPECT_EQ(result, "отрицательное нечетное число");
}

/// Проверка нуля.
TEST(If42, Zero) {
    // Arrange
    int number = 0;

    // Act
    std::string result = describe_signed_number(number);

    // Assert
    EXPECT_EQ(result, "нулевое число");
}

// IF51
// По условию задачи If30.

/// Определяет четность и количество цифр числа от 1 до 999.
std::string describe_digit_number(int number) {
    std::string parity;

    if (number % 2 == 0) {
        parity = "четное";
    }
    else {
        parity = "нечетное";
    }

    std::string digits;

    if (number < 10) {
        digits = "однозначное";
    }
    else if (number < 100) {
        digits = "двузначное";
    }
    else {
        digits = "трехзначное";
    }

    return parity + " " + digits + " число";
}

/// Проверка однозначного числа.
TEST(If51, OneDigit) {
    // Arrange
    int number = 1;

    // Act
    std::string result = describe_digit_number(number);

    // Assert
    EXPECT_EQ(result, "нечетное однозначное число");
}

/// Проверка двузначного числа.
TEST(If51, TwoDigits) {
    // Arrange
    int number = 24;

    // Act
    std::string result = describe_digit_number(number);

    // Assert
    EXPECT_EQ(result, "четное двузначное число");
}

/// Проверка трехзначного четного числа.
TEST(If51, ThreeDigitsEven) {
    // Arrange
    int number = 100;

    // Act
    std::string result = describe_digit_number(number);

    // Assert
    EXPECT_EQ(result, "четное трехзначное число");
}

/// Проверка максимального трехзначного числа.
TEST(If51, MaximumNumber) {
    // Arrange
    int number = 999;

    // Act
    std::string result = describe_digit_number(number);

    // Assert
    EXPECT_EQ(result, "нечетное трехзначное число");
}
