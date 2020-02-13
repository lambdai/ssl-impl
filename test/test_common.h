#pragma once

#include <string>
#include <vector>

void EXPECT_HEX_EQ(const std::vector<unsigned int> &lhs,
                   const std::string &rhs);

void EXPECT_HEX_EQ(const std::vector<unsigned char> &lhs,
                   const std::string &rhs);