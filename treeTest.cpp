#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <gtest/gtest.h>
#include "tree.h"

class TestWithMemoryLeakDetector : public ::testing::Test {
    _CrtMemState memState_;
public:
    TestWithMemoryLeakDetector() {
        _CrtMemCheckpoint(&memState_);
    }
    ~TestWithMemoryLeakDetector() {
        _CrtMemState stateNow, stateDiff;
        _CrtMemCheckpoint(&stateNow);
        if (_CrtMemDifference(&stateDiff, &memState_, &stateNow))
            _CrtMemDumpStatistics( &stateDiff );
    }
};

class OneNodeTest : public TestWithMemoryLeakDetector {
protected:
    Tree tree;
};

class GenerateTreeTest : public TestWithMemoryLeakDetector {
protected:
    Tree tree = Tree(10);
    void SetUp() override {
        EXPECT_NO_THROW(tree.insert(15));
        EXPECT_NO_THROW(tree.insert(20));
        EXPECT_NO_THROW(tree.insert(5));
        EXPECT_NO_THROW(tree.insert(7));
    }
};

TEST_F(OneNodeTest, TreeBuildTest1) {
    Tree::iterator it;
    it = tree.begin();
    EXPECT_EQ(*it, 1);
    it = tree.end();
    EXPECT_EQ(*it, 1);
    EXPECT_TRUE(tree.begin() == tree.end());
    EXPECT_FALSE(tree.begin() != tree.end());
}

TEST_F(GenerateTreeTest, TreeBuildTest2) {
    Tree::iterator it = tree.begin();
    EXPECT_EQ(*(it--), 7);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 20);
    EXPECT_EQ(*(it++), 15);
    EXPECT_EQ(*(it++), 10);
    EXPECT_EQ(*(it++), 10);
    EXPECT_EQ(*(++it), 10);
}

class GeneralTest : public TestWithMemoryLeakDetector {
protected:
    Tree tree = Tree(10);
    void SetUp() override {
        EXPECT_NO_THROW(tree.insert(14));
        EXPECT_NO_THROW(tree.insert(5));
        EXPECT_NO_THROW(tree.insert(3));
        EXPECT_NO_THROW(tree.insert(1));
        EXPECT_NO_THROW(tree.insert(6));
        EXPECT_NO_THROW(tree.insert(8));
        EXPECT_NO_THROW(tree.insert(9));
        EXPECT_NO_THROW(tree.insert(7));
        EXPECT_NO_THROW(tree.insert(11));
        EXPECT_NO_THROW(tree.insert(12));
        EXPECT_NO_THROW(tree.insert(16));
        EXPECT_NO_THROW(tree.insert(15));
        EXPECT_NO_THROW(tree.insert(17));
    }
};

TEST_F(GeneralTest, IncrementTest) {
    auto it1 = tree.begin();
    auto it2 = tree.begin();
    EXPECT_EQ(*(it1++), 1);
    EXPECT_EQ(*(it1++), 3);
    EXPECT_EQ(*(++it2), 3);
    EXPECT_EQ(*(it1++), 7);
    EXPECT_EQ(*(++it2), 7);
    EXPECT_EQ(*(it1++), 9);
    EXPECT_EQ(*(++it2), 9);
    EXPECT_EQ(*(it1++), 8);
    EXPECT_EQ(*(++it2), 8);
    EXPECT_EQ(*(it1++), 6);
    EXPECT_EQ(*(++it2), 6);
    EXPECT_EQ(*(it1++), 5);
    EXPECT_EQ(*(++it2), 5);
    EXPECT_EQ(*(it1++), 12);
    EXPECT_EQ(*(++it2), 12);
    EXPECT_EQ(*(it1++), 11);
    EXPECT_EQ(*(++it2), 11);
    EXPECT_EQ(*(it1++), 15);
    EXPECT_EQ(*(++it2), 15);
    EXPECT_EQ(*(it1++), 17);
    EXPECT_EQ(*(++it2), 17);
    EXPECT_EQ(*(it1++), 16);
    EXPECT_EQ(*(++it2), 16);
    EXPECT_EQ(*(it1++), 14);
    EXPECT_EQ(*(++it2), 14);
    EXPECT_EQ(*(it1++), 10);
    EXPECT_EQ(*(++it2), 10);
}

TEST_F(GeneralTest, DecrementTest) {
    auto it1 = tree.end();
    auto it2 = tree.end();
    EXPECT_EQ(*(it1--), 10);
    EXPECT_EQ(*(it1--), 14);
    EXPECT_EQ(*(--it2), 14);
    EXPECT_EQ(*(it1--), 16);
    EXPECT_EQ(*(--it2), 16);
    EXPECT_EQ(*(it1--), 17);
    EXPECT_EQ(*(--it2), 17);
    EXPECT_EQ(*(it1--), 15);
    EXPECT_EQ(*(--it2), 15);
    EXPECT_EQ(*(it1--), 11);
    EXPECT_EQ(*(--it2), 11);
    EXPECT_EQ(*(it1--), 12);
    EXPECT_EQ(*(--it2), 12);
    EXPECT_EQ(*(it1--), 5);
    EXPECT_EQ(*(--it2), 5);
    EXPECT_EQ(*(it1--), 6);
    EXPECT_EQ(*(--it2), 6);
    EXPECT_EQ(*(it1--), 8);
    EXPECT_EQ(*(--it2), 8);
    EXPECT_EQ(*(it1--), 9);
    EXPECT_EQ(*(--it2), 9);
    EXPECT_EQ(*(it1--), 7);
    EXPECT_EQ(*(--it2), 7);
    EXPECT_EQ(*(it1--), 3);
    EXPECT_EQ(*(--it2), 3);
    EXPECT_EQ(*(it1--), 1);
    EXPECT_EQ(*(--it2), 1);
}

TEST_F(GeneralTest, ForIteration) {
    int count = 0;
    for (auto it = tree.begin(); it != tree.end(); it++)
        count++;
    EXPECT_EQ(count, 13);
}
