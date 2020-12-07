#include "WorkerCRC.h"
#include "test_utils.h"

#include <gtest/gtest.h>
#include <cstdint>



TEST(TWorkerCRC, TEST_EMPTY){
  std::string fname {"../test_data/test_empty.tst"};
  try {
      auto fsize = getFileSize(fname);
      WorkerCRC worker_crc(fname, fsize);
      worker_crc.init();
      worker_crc.run();
      auto result = worker_crc.getResult();

      ASSERT_EQ(result,"0");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_ONE_BYTE_ZERO){
  std::string fname {"../test_data/test_0_CRC.tst"};
  try {
      auto fsize = getFileSize(fname);
      WorkerCRC worker_crc(fname, fsize);
      worker_crc.init();
      worker_crc.run();
      auto result = worker_crc.getResult();

      ASSERT_EQ(result,"48");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_ONE_BYTE_ONE){
  std::string fname {"../test_data/test_1_CRC.tst"};
  try {
      auto fsize = getFileSize(fname);
      WorkerCRC worker_crc(fname, fsize);
      worker_crc.init();
      worker_crc.run();
      auto result = worker_crc.getResult();

      ASSERT_EQ(result,"49");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_ONE_BYTE_DIFF){
  std::string fname1 {"../test_data/test_0_CRC.tst"};
  std::string fname2 {"../test_data/test_1_CRC.tst"};
  try {
      auto fsize1 = getFileSize(fname1);
      WorkerCRC worker_crc1(fname1, fsize1);
      worker_crc1.init();
      worker_crc1.run();

      auto fsize2 = getFileSize(fname2);
      WorkerCRC worker_crc2(fname2, fsize2);
      worker_crc2.init();
      worker_crc2.run();

      std::string::size_type sz = 0;
      auto result1 = std::stoull(worker_crc1.getResult(), &sz, 0);
      auto result2 = std::stoull(worker_crc2.getResult(), &sz, 0);
      ASSERT_EQ(result2 - result1, 1);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_FOUR_BYTE_ZERO){
  std::string fname {"../test_data/test_3_CRC.tst"};
  try {
      auto fsize = getFileSize(fname);
      WorkerCRC worker_crc(fname, fsize);
      worker_crc.init();
      worker_crc.run();
      auto result = worker_crc.getResult();

      ASSERT_EQ(result,"808464432");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerCRC, TEST_FOUR_BYTE_ONCE){
  std::string fname {"../test_data/test_4_CRC.tst"};
  try {
      auto fsize = getFileSize(fname);
      WorkerCRC worker_crc(fname, fsize);
      worker_crc.init();
      worker_crc.run();
      auto result = worker_crc.getResult();

      ASSERT_EQ(result,"825307441");
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
