#include <gtest/gtest.h>

#include "nnoops/functions/point.hpp"

using namespace nnoops;

TEST(Point, CommonPoints_test) {
  Point<3> point = {1, 1, 1};

  EXPECT_EQ(point, Point<3>::unit_point());
  EXPECT_NE(point, Point<3>::zero_point());

  point = {0, 0, 0};

  EXPECT_EQ(point, Point<3>::zero_point());
  EXPECT_NE(point, Point<3>::unit_point());
}

TEST(Point, Basic_test) {
  Point<3> point1 = {1, 2, 3};
  Point<3> point2 = {2, 3, 5};

  EXPECT_EQ(point1[0], 1);
  EXPECT_EQ(point1[1], 2);
  EXPECT_EQ(point1[2], 3);

  EXPECT_EQ(point2[0], 2);
  EXPECT_EQ(point2[1], 3);
  EXPECT_EQ(point2[2], 5);

  point1[0] = 2;
  point1[1] = 3;
  point1[2] = 5;

  EXPECT_EQ(point1, point2);
  point1[0] = 1;
  EXPECT_NE(point1, point2);

  point1 = point2;

  EXPECT_EQ(point1, point2);

  point1 = {1, 2, 3};
  EXPECT_NE(point1, point2);

  EXPECT_THROW((point1 = {1, 2, 3, 3}), std::out_of_range);
  EXPECT_THROW((point2[3]), std::out_of_range);
}

TEST(Point, increment_decrement_test) {
  Point<3> point1 = {1, 2, 3};
  Point<3> point2 = {2, 3, 5};

  Point<3> point3 = {3, 5, 8};

  EXPECT_EQ(point3, (point1 + point2));

  EXPECT_EQ(point3++, (point1 + point2));
  EXPECT_NE(point3, (point1 + point2));
  EXPECT_NE(point3--, (point1 + point2));
  EXPECT_EQ(point3, (point1 + point2));

  EXPECT_NE(++point3, (point1 + point2));
  EXPECT_EQ(--point3, (point1 + point2));
}

TEST(Point, addition_substraction_test) {
  Point<3> point1 = {1, 2, 3};
  Point<3> point2 = {2, 3, 5};

  Point<3> point3 = {1, 1, 2};

  EXPECT_EQ(point3, (point2 - point1));

  point3 = {2, 4, 6};
  EXPECT_EQ(point3, 2 * point1);
  EXPECT_EQ(point3, point1 * 2);

  point1 *= 2;

  EXPECT_EQ(point3, point1);

  point1 += 4;
  point3 = {6, 8, 10};
  EXPECT_EQ(point3, point1);

  point1 -= 4;
  point3 = {2, 4, 6};
  EXPECT_EQ(point3, point1);

  point3 = {6, 8, 10};
  EXPECT_EQ(point3, point1 + 4);
  EXPECT_EQ(point3, 4 + point1);
  point1 += 4;
  EXPECT_EQ(point3 - 4, point1 - 4);
  EXPECT_NE(point3 - 4, 4 - point1);
  EXPECT_EQ(4 - point3, 4 - point1);

  point1 = {1, 2, 3};
  point2 = {2, 3, 5};
  EXPECT_EQ(23, point1 * point2);

  point3 = point1 + point2 + point3;

  point3 = {4, 7, 11};
  EXPECT_EQ(point3, point1 + point2 + point1);
}

TEST(Point, toPrettyString_test) {
  Point<3> point = {2.0, 3.6, 5};
  EXPECT_EQ(toPrettyString(point), "(2.000000, 3.600000, 5.000000)");

  point = {3.6, 2.7, -1.3};
  EXPECT_EQ(toPrettyString(point), "(3.600000, 2.700000, -1.300000)");
}