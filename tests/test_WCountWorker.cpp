#include "WorkerWCount.h"
#include "test_utils.h"

#include <gtest/gtest.h>
#include <cstdint>

std::string init_and_run(const std::string fname,
                         const std::string word){
    auto fsize = getFileSize(fname);
    WorkerWCount worker_wcount(fname, word, fsize);
    worker_wcount.init();
    worker_wcount.run();
    return worker_wcount.getResult();
}

TEST(TWorkerWCount, TEST_EMPTY){
  try {
      auto result = init_and_run("../test_data/test_empty.tst", "any");
      ASSERT_EQ(result,"0");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_SIMPLE_1){
  try {
      auto result = init_and_run("../test_data/test_w_0.tst", "123");
      ASSERT_EQ(result,"4");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}


TEST(TWorkerWCount, TEST_SIMPLE_2){
  try {
      auto result = init_and_run("../test_data/test_w_1.tst", "1");
      ASSERT_EQ(result,"14");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_SIMPLE_3){
  try {
      auto result = init_and_run("../test_data/test_w_wiki.tst", "города");
      ASSERT_EQ(result,"3");
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
