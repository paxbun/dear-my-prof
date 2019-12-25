// Copyright (c) 2019 Dear My Professor Authors
// Author: paxbun

#include <core/StringTransform.hpp>
#include <core/StringTransformFactory.hpp>

#include <string>

struct TestCase
{
    std::string targetStr;
    std::string transformFunc;
    std::string desired;
};

#define TEST_CASE(target, trans, des)                                          \
    {                                                                          \
        u8## #target, u8## #trans, u8## #des                                   \
    }

TestCase testCases[] = {
    TEST_CASE(가방, 이, 가방이), TEST_CASE(기차, 이, 기차가),
    TEST_CASE(가방, 가, 가방이), TEST_CASE(기차, 가, 기차가),
    TEST_CASE(가방, 은, 가방은), TEST_CASE(기차, 은, 기차는),
    TEST_CASE(가방, 는, 가방은), TEST_CASE(기차, 는, 기차는),
};

int main()
{
    for (auto& testCase : testCases)
    {
        auto transform
            = StringTransformFactory::GetTransform(testCase.transformFunc);

        if (transform->Transform(testCase.targetStr) != testCase.desired)
            return 1;
    }
    return 0;
}