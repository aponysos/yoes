#include <gtest/gtest.h>
#include "yoes.h"

using namespace std;

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class YoesTest : public testing::Test
{
protected:
  static void SetUpTestCase()
  {
  }
  static void TearDownTestCase()
  {
  }
  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
  }

public:
  static yoes yoes_;

};

//static
yoes YoesTest::yoes_;

TEST_F(YoesTest, HandleLoadHeaderwordsTxtFile)
{
  EXPECT_EQ(true, yoes_.load_headwords_txtfile("headwords.txt"));
}

TEST_F(YoesTest, HandleLoadFindoutmoreTxtFile)
{
  EXPECT_EQ(true, yoes_.load_findoutmore_txtfile("findoutmore.txt"));
}

TEST_F(YoesTest, HandleDumpTxtFile)
{
  EXPECT_EQ(true, yoes_.dump_txtfile(cout));
}
