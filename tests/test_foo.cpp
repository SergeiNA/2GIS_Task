#include "common.h"

#include <gtest/gtest.h>
#include <cstdint>

/**
 * @brief Простой тест на проверку сборки
 * 
 */
TEST(FOO, TEST_BAR){
  ASSERT_EQ(1, 1);
}

// TEST(FOO, TEST_FOO){

//   ASSERT_EQ(1, 1);
// }

int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
