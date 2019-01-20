#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <stack>
#include <vector>

#include "IOperand.hpp"
#include "CommandFactory.hpp"
#include "OpFactory.hpp"

TEST (UnitCommandFactory, Create_Empty_NoThrow) {
    const std::vector<std::string> empty;

    CmdFactory::commands_t out;
    EXPECT_NO_THROW(out = CmdFactory().create(empty));
    EXPECT_EQ(out.size(), 0) << "unexpected commands has been created";
}

TEST (UnitCommandFactory, Create_Command_Ok) {
    // TODO: create parametrized test case instead
    const std::vector<std::string> available_cmds{"add", "sub", "div", "mul",
                                                 "print", "dump", "push", "pop",
                                                 "mod", "assert", "exit"};

    CmdFactory::commands_t out;
    for (const auto &cmd : available_cmds) {
        EXPECT_NO_THROW(out.push_back(CmdFactory().create({cmd}).front()));
    }
    EXPECT_EQ(out.size(), available_cmds.size());
}

TEST (UnitCommandFactory, Create_UnknownCommand_Fail) {
    const std::vector<std::string> unknown{"make_me_happy"};

    CmdFactory::commands_t out;
    EXPECT_NO_THROW(out = CmdFactory().create(unknown));
    EXPECT_EQ(out.size(), 0) << "unexpected commands has been created";
}
