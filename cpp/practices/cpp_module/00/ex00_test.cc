#include <gtest/gtest.h>
#include "ex00/megaphone.hpp"
#include <sstream>
#include <string>
#include <vector>

TEST(Ex00Test, BasicAssertion) {
	testing::internal::CaptureStdout();
	std::vector<std::string> argvVec = {"./megaphone"};
	megaphone(1, NULL);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
