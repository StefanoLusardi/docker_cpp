#include <test_lib.hpp>

namespace dkpp::test
{
TEST_F(test_lib, test_1)
{ 
    _lib->print("docker_cpp test");
    ASSERT_TRUE(true));
}

TEST_F(test_lib, test_2)
{ 
    ASSERT_EQ(1+1, 2);
}

}