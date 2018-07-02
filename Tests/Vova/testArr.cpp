//
// Created by vov4ik on 29-Jun-18.
//
#include "catch.hpp"
#include "mtm_array.h"

using std::array;
using std::vector;
using std::string;

TEST_CASE("Simple integers array") {
  Array<int, 50> iArr;
  int i = 0;
  for (auto&& item : iArr) {
    item = i++;
  }
  SECTION("Checking functionality of simple array.") {
    SECTION("Checking if the elements are assigned correctly") {
      REQUIRE(iArr[0] == 0);
      REQUIRE(iArr[49] == 49);
    }
    SECTION(
        "Checking if exceptions are thrown SECTION accessing elements out of range") {
      REQUIRE_THROWS_AS(iArr[50], std::out_of_range);
    }
    SECTION("Checking access denial to elements by negative index") {
      REQUIRE_THROWS_AS(iArr[-1], std::out_of_range);
    }
    SECTION("Checking begin iterators position") {
      REQUIRE(*iArr.begin() == 0);
    }
    SECTION(
        "Checking correctness of end position of iterator(one element after last)") {
      REQUIRE_THROWS_AS(*iArr.end(), std::out_of_range);
    }
  }
}
TEST_CASE("Constant array test:") {
  Array<int, 50> iArr;
  int i = 0;
  for (auto&& item : iArr) {
    item = i++;
  }
  const Array<int, 50>& cIArr = iArr;
  SECTION("Checking functionality of simple array.") {
    SECTION("Checking if the elements are assigned correctly") {
      int i = 0;
      for (auto&& arr : cIArr) {
        REQUIRE( cIArr[i] ==  i);
        i++;
      }
    }
    SECTION(
        "Checking if exceptions are thrown SECTION accessing elements out of range") {
      REQUIRE_THROWS_AS(cIArr[50], std::out_of_range);
    }
    SECTION("Checking access denial to elements by negative index") {
      REQUIRE_THROWS_AS(cIArr[-1], std::out_of_range);
    }
    SECTION("Checking begin iterators position") {
      REQUIRE(*cIArr.begin() == 0);
    }
    SECTION(
        "Checking correctness of end position of iterator(one element after last)") {
      REQUIRE_THROWS_AS(*cIArr.end(), std::out_of_range);
    }
  }
}
TEST_CASE("Testing const Array functionality") {
  Array<int, 50> iArr;
  int i = 0;
  for (auto&& item : iArr) {
    item = i++;
  }
  const Array<int, 50>& iCArr = iArr;
  SECTION("Checking functionality of simple const array.") {
    SECTION("Checking if the elements are assigned correctly") {
      REQUIRE(iCArr[0] == 0);
      REQUIRE(iCArr[49] == 49);
    }
    SECTION(
        "Checking if exceptions are thrown SECTION accessing elements out of range") {
      REQUIRE_THROWS_AS(iCArr[50], std::out_of_range);
    }
    SECTION("Checking access denial to elements by negative index") {
      REQUIRE_THROWS_AS(iCArr[-1], std::out_of_range);
    }
    SECTION("Checking begin iterators position") {
      REQUIRE(*iCArr.begin() == 0);
    }
    SECTION(
        "Checking correctness of end position of iterator(one element after last)") {
      REQUIRE_THROWS_AS(*iCArr.end(), std::out_of_range);
    }
  }
}
TEST_CASE("Checking copy constructor functionality") {
  Array<int, 50> iArr;
  int i = 0;
  for (auto&& item : iArr) {
    item = i++;
  }
  Array<int, 50> iArrCTOR(iArr);
  SECTION("Checking assignments of elements") {
    REQUIRE(iArrCTOR[0] == 0);
    REQUIRE(iArrCTOR[49] == 49);
  }
}
TEST_CASE("Checking assignment operator functionality") {
  Array<int, 50> iArr;
  int i = 0;
  for (auto&& item : iArr) {
    item = i++;
  }
  Array<int, 50> iArrAssignment = iArr;
  SECTION("Checking assignments of elements") {
    REQUIRE(iArrAssignment[0] == 0);
    REQUIRE(iArrAssignment[49] == 49);
  }
}
TEST_CASE("Testing Array of vectors") {
  auto* vArr = new Array<vector<int>, 50>;
  unsigned long long int i = 0;
  for (auto&& arr : *vArr) {
    arr.resize(i++);
    unsigned int k = 0;
    for (auto&& item : arr) {
      item = k;
    }
  }
  unsigned long long int i2 = 0;
  for (auto&& arr : *vArr) {
    REQUIRE(arr.size() == i2++);
    unsigned int k = 0;
    for (auto&& item : arr) {
      REQUIRE(item == k);
    }
  }
  delete vArr;
}
TEST_CASE("Testing Array of strings") {
  Array<string, 50> sArr;
  string a = "String";
  int i = 0;
  for (auto&& item : sArr) {
    item = a + std::to_string(i++);
  }
  int n = 0;
  SECTION("Testing string assignment:") {
    for (auto&& item : sArr) {
      REQUIRE(item == a + std::to_string(n++));
    }
  }
  SECTION("Testing iterator's begin position") {
    REQUIRE(*sArr.begin() == a + std::to_string(0));
  }
  SECTION("Testing iterator's end position") {
    REQUIRE_THROWS_AS(*sArr.end(), std::out_of_range);
  }
}