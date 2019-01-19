#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <stack>
#include <vector>

#include "IOperand.hpp"
#include "Parser.hpp"
#include "OpFactory.hpp"

TEST (UnitParser, Operate_Empty_NoThrow) {
    std::stack<const IOperand*> stack;
    OpFactory factory;
    std::vector<std::string> empty;

    EXPECT_NO_THROW(Parser().operate(empty, stack, factory));
}

TEST (UnitParser, DISABLED_Operate_Command_Ok) {
    EXPECT_TRUE(false) << "not implemented";
}
