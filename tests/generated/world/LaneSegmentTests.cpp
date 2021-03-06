/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2018-2019 Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 *    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *    OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *    POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#include <gtest/gtest.h>
#include <limits>
#include "ad_rss/world/LaneSegment.hpp"

class LaneSegmentTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad_rss::world::LaneSegment value;
    ::ad_rss::world::LaneSegmentId valueId(std::numeric_limits<::ad_rss::world::LaneSegmentId>::lowest());
    value.id = valueId;
    ::ad_rss::world::LaneSegmentType valueType(::ad_rss::world::LaneSegmentType::Normal);
    value.type = valueType;
    ::ad_rss::world::LaneDrivingDirection valueDrivingDirection(::ad_rss::world::LaneDrivingDirection::Bidirectional);
    value.drivingDirection = valueDrivingDirection;
    ::ad_rss::physics::MetricRange valueLength;
    ::ad_rss::physics::Distance valueLengthMinimum(0.);
    valueLength.minimum = valueLengthMinimum;
    ::ad_rss::physics::Distance valueLengthMaximum(0.);
    valueLength.maximum = valueLengthMaximum;
    valueLength.maximum = valueLength.minimum;
    valueLength.minimum = valueLength.maximum;
    value.length = valueLength;
    ::ad_rss::physics::MetricRange valueWidth;
    ::ad_rss::physics::Distance valueWidthMinimum(0.);
    valueWidth.minimum = valueWidthMinimum;
    ::ad_rss::physics::Distance valueWidthMaximum(0.);
    valueWidth.maximum = valueWidthMaximum;
    valueWidth.maximum = valueWidth.minimum;
    valueWidth.minimum = valueWidth.maximum;
    value.width = valueWidth;
    mValue = value;
  }

  ::ad_rss::world::LaneSegment mValue;
};

TEST_F(LaneSegmentTests, copyConstruction)
{
  ::ad_rss::world::LaneSegment value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, moveConstruction)
{
  ::ad_rss::world::LaneSegment value(std::move(::ad_rss::world::LaneSegment(mValue)));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, copyAssignment)
{
  ::ad_rss::world::LaneSegment value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, moveAssignment)
{
  ::ad_rss::world::LaneSegment value;
  value = std::move(::ad_rss::world::LaneSegment(mValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, comparisonOperatorEqual)
{
  ::ad_rss::world::LaneSegment valueA = mValue;
  ::ad_rss::world::LaneSegment valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorIdDiffers)
{
  ::ad_rss::world::LaneSegment valueA = mValue;
  ::ad_rss::world::LaneSegmentId id(std::numeric_limits<::ad_rss::world::LaneSegmentId>::max());
  valueA.id = id;
  ::ad_rss::world::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorTypeDiffers)
{
  ::ad_rss::world::LaneSegment valueA = mValue;
  ::ad_rss::world::LaneSegmentType type(::ad_rss::world::LaneSegmentType::Intersection);
  valueA.type = type;
  ::ad_rss::world::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorDrivingDirectionDiffers)
{
  ::ad_rss::world::LaneSegment valueA = mValue;
  ::ad_rss::world::LaneDrivingDirection drivingDirection(::ad_rss::world::LaneDrivingDirection::Negative);
  valueA.drivingDirection = drivingDirection;
  ::ad_rss::world::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorLengthDiffers)
{
  ::ad_rss::world::LaneSegment valueA = mValue;
  ::ad_rss::physics::MetricRange length;
  ::ad_rss::physics::Distance lengthMinimum(1e6);
  length.minimum = lengthMinimum;
  ::ad_rss::physics::Distance lengthMaximum(1e6);
  length.maximum = lengthMaximum;
  length.maximum = length.minimum;
  length.minimum = length.maximum;
  valueA.length = length;
  ::ad_rss::world::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorWidthDiffers)
{
  ::ad_rss::world::LaneSegment valueA = mValue;
  ::ad_rss::physics::MetricRange width;
  ::ad_rss::physics::Distance widthMinimum(1e6);
  width.minimum = widthMinimum;
  ::ad_rss::physics::Distance widthMaximum(1e6);
  width.maximum = widthMaximum;
  width.maximum = width.minimum;
  width.minimum = width.maximum;
  valueA.width = width;
  ::ad_rss::world::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}
