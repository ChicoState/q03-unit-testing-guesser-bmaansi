/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, constructor_with_less_than_32)
{
	Guesser g("hello");
	bool actual = g.match("hello");
    ASSERT_EQ(true, actual);
}


TEST(GuesserTest, constructor_with_more_than_32)
{
	Guesser g("hellohellohellohellohellohellohello");
	bool actual = g.match("hellohellohellohellohellohellohe");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, incorrect_match_guess_larger)
{
	Guesser g("hello");
	bool actual = g.match("hello!");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, incorrect_match_guess_shorter)
{
	Guesser g("hello!");
	bool actual = g.match("hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, remaining_1)
{
	Guesser g("hello!");
	g.match("hello");
	unsigned int actual = g.remaining();
    ASSERT_EQ(2, actual);
}

TEST(GuesserTest, remaining_2)
{
	Guesser g("hello!");
	g.match("hello");
	g.match("hello");
	unsigned int actual = g.remaining();
    ASSERT_EQ(1, actual);
}

TEST(GuesserTest, remaining_3)
{
	Guesser g("hello!");
	g.match("hello");
	g.match("hello");
	g.match("hello");
	unsigned int actual = g.remaining();
    ASSERT_EQ(0, actual);
}

TEST(GuesserTest, remaining_reset)
{
	Guesser g("hello!");
	g.match("hello");
	g.match("hello");
	g.match("hello!");
	unsigned int actual = g.remaining();
    ASSERT_EQ(3, actual);
}

TEST(GuesserTest, lockout_thro_brute_force)
{
	Guesser g("hello!");
	bool actual = g.match("hello0000");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, lockout_too_many_guesses)
{
	Guesser g("hello!");
	g.match("hello0000");
	g.match("hi");
	g.match("hello0000");
	bool actual = g.match("hello!");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, remaining_after_brute_force)
{
	Guesser g("hello!");
	g.match("thisisalongguess");
	int actual = g.remaining();
    ASSERT_EQ(0, actual);
}