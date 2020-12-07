#include "WorkerStateWCount.h"
#include "test_utils.h"

#include <gtest/gtest.h>
#include <cstdint>

std::string init_and_run(const std::string fname,
                         const std::string word){
    auto fsize = getFileSize(fname);
    WorkerStateWCount worker_wcount(fname, word, fsize);
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

TEST(TWorkerWCount, TEST_WIKI_1){
  try {
      auto result = init_and_run("../test_data/test_w_wiki.tst", "данных");
      ASSERT_EQ(result,"15");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_WIKI_2){
  try {
      auto result = init_and_run("../test_data/test_w_wiki.tst", "ломаные");
      ASSERT_EQ(result,"1");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_WIKI_3){
  try {
      auto result = init_and_run("../test_data/test_w_wiki.tst", "систем");
      ASSERT_EQ(result,"11");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_PUNC){
  try {
      auto result = init_and_run("../test_data/test_w_punc.tst", "123");
      ASSERT_EQ(result,"6");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_SCOPE_1){
  try {
      auto result = init_and_run("../test_data/test_w_scope_1.tst", "123");
      ASSERT_EQ(result,"5");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    FAIL();
  }
}

TEST(TWorkerWCount, TEST_SCOPE_2){
  try {
      auto result = init_and_run("../test_data/test_w_scope_2.tst", "123");
      ASSERT_EQ(result,"5");
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
