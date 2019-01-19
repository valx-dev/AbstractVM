#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "Lexer.hpp"

TEST (UnitLexer, Explode_Empty_NoThrow) {
    EXPECT_NO_THROW(Lexer().explode(""));
}

TEST (UnitLexer, Explode_Spaces_Ok) {
    const Lexer::words_t expected{"one", "two", "three"};

    std::string input = expected[0];
    // NOTE: skip first element as it was already processed
    std::for_each(expected.cbegin() + 1, expected.cend(),
                  [&input](const auto item) {
                        input += ' ' + item;
                    });

    const Lexer::words_t parsed = Lexer().explode(input);

    EXPECT_EQ(parsed, expected) << "failed to parse argument";
}

TEST (UnitLexer, Explode_ExtraSpace_Ok) {
    const Lexer::words_t expected{"one", "two", "three"};

    std::string input;
    for (const auto &item : expected) {
        input += item + " ";
    }

    const Lexer::words_t parsed = Lexer().explode(input);

    EXPECT_EQ(parsed, expected) << "failed to parse argument";
}

TEST (UnitLexer, Explode_Parentheses_Ok) {
    const Lexer::words_t expected{"one", "two", "three"};

    std::string input;
    for (const auto &item : expected) {
        input += '(' + item + ')';
    }

    const Lexer::words_t parsed = Lexer().explode(input);

    EXPECT_EQ(parsed, expected) << "failed to parse argument";
}

TEST (UnitLexer, Explode_Mixed_Ok) {
    const Lexer::words_t expected{"one", "two", "three"};

    const std::string input{"one (two three)"};

    const Lexer::words_t parsed = Lexer().explode(input);

    EXPECT_EQ(parsed, expected) << "failed to parse argument";
}

TEST (UnitLexer, Explode_Unterminated_Ok) {
    const Lexer::words_t expected{"one", "two", "three"};

    const std::string input{"one (two three"};

    const Lexer::words_t parsed = Lexer().explode(input);

    EXPECT_EQ(parsed, expected) << "failed to parse argument";
}

TEST (UnitLexer, Explode_MixedUnterminated_Ok) {
    const Lexer::words_t expected{"one", "two", "three"};

    const std::string input{"one ((two ()three"};

    const Lexer::words_t parsed = Lexer().explode(input);

    EXPECT_EQ(parsed, expected) << "failed to parse argument";
}
