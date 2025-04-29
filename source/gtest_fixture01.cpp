#include <gtest/gtest.h>

extern int allocate_memory(int *ptrMemory, int size);

class mallocTest : public ::testing::Test
{
protected:
     int *ptrMemory;
     int nSize;

     virtual void SetUp()
     {
	nSize = 10;
        ptrMemory = (int *)malloc(nSize * sizeof(int));	     
     }
     
     virtual void TearDown()
     {
	if(ptrMemory != NULL)
            free(ptrMemory);
     }
};

TEST_F(mallocTest, validPointerTest)
{
  EXPECT_EQ(allocate_memory(ptrMemory, nSize), 0);
}

TEST_F(mallocTest, nullPointerHandlingTest01)
{
  ptrMemory = NULL;

  EXPECT_EQ(allocate_memory(ptrMemory, nSize), -1);
}

//TEST_F(mallocTest, nullPointerHandlingTest02)
TEST_F(mallocTest, DISABLED_nullPointerHandlingTest02)
{
  ptrMemory = NULL;

  ASSERT_EXIT(allocate_memory(ptrMemory, nSize), ::testing::ExitedWithCode(-1), "Error: Null Pointer was passed !!!");
  ASSERT_DEATH (allocate_memory(ptrMemory, nSize), "Error:Negative Input");
}

int main(int argc, char **argv)
{
   testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
