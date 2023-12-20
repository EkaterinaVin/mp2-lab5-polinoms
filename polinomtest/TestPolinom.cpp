#include "TPolinom.h"
#include <gtest.h>

TEST(Polinom, Created_polinom_is_empty) {
	TPolinom a;
	EXPECT_TRUE(a.IsEmpty());
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
	vector<int> v = { 1, 111 };
	TPolinom a(v);
	EXPECT_FALSE(a.IsEmpty());
}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
	vector<int> v = { 1, 111, 1, 111 };
	TPolinom a(v);
	EXPECT_EQ(a.GetCurrentItem().GetCoef(), 2);
}


TEST(Polinom, Can_not_get_monom_from_empty_polinom) {
	TPolinom a;
	ASSERT_ANY_THROW(a.GetCurrentItem());
}

TEST(Polinom, Copied_polinom_is_equal_copiable) {
	vector<int> v = { 1, 111 };
	TPolinom a(v);
	TPolinom b(a);
	EXPECT_TRUE(a== b);
}


TEST(Polinom, Correct_constant_multiply) {
	vector<int> v = { 1, 111 };
	vector<int> v1 = { 3, 111 };
	TPolinom a(v);
	a = a * 3;
	TPolinom b(v1);
	EXPECT_TRUE(a==b);
}

TEST(Polinom, Correct_polinom_addition) {
	
	vector<int> v = { 1, 111 };
	vector<int> v1 = { 3, 333 };
	vector<int> v2 = { 3, 333, 1, 111 };
	TPolinom a(v);
	TPolinom b(v1);
	TPolinom c(v2);
	a = a + b;
	EXPECT_TRUE(a==c);
}


