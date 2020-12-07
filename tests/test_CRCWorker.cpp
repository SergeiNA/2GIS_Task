#include "WorkerCRC.h"
#include "test_utils.h"

#include <gtest/gtest.h>
#include <cstdint>


std::string init_and_run(const std::string fname){
    auto fsize = getFileSize(fname);
    WorkerCRC worker_crc(fname, fsize);
    worker_crc.init();
    worker_crc.run();
    return worker_crc.getResult();
}

TEST(TWorkerCRC, TEST_EMPTY){
  try {
      auto result = init_and_run("../test_data/test_empty.tst");
      ASSERT_EQ(result, "0");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_ONE_BYTE_ZERO){
  try {
      auto result = init_and_run("../test_data/test_0_CRC.tst");
      ASSERT_EQ(result,"48"); // 0011 0000
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_ONE_BYTE_ONE){
  try {
      auto result = init_and_run("../test_data/test_1_CRC.tst");
      ASSERT_EQ(result,"49"); // 0011 0001
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_FOUR_BYTE_ALL_ZERO){
  try {
      auto result = init_and_run("../test_data/test_3_CRC.tst");
      ASSERT_EQ(result,"808464432"); // 0011 0000 0011 0000 0011 0000 0011 0000
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_FOUR_BYTE_ALL_ONE){
  try {
      auto result = init_and_run("../test_data/test_4_CRC.tst");
      ASSERT_EQ(result,"808464433"); // 0011 0001 0011 0001 0011 0001 0011 0001
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_FIVE_BYTE_ALL_ZERO){
  try {
      auto result = init_and_run("../test_data/test_5_CRC.tst");

      ASSERT_EQ(result,"808464384"); // 0011 0000 0011 0000 0011 0000 0000 0000
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_CUSTOM){
  try {
      auto result = init_and_run("../test_data/test_6_CRC.tst");
      ASSERT_EQ(result,"1"); // 0000 0000 0000 0000 0000 0000 0000 0001
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

int main(int argc, char **argv) {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
