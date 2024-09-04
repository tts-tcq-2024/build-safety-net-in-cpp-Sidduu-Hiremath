#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesStandardName) {
    EXPECT_EQ(generateSoundex("Siddu"), "S3");
}

TEST(SoundexTest, HandlesSimilarSoundingNames) {
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(SoundexTest, HandlesDifferentCases) {
    EXPECT_EQ(generateSoundex("Prajwal"), "P624");
    EXPECT_EQ(generateSoundex("prajwal"), "P624");
}

TEST(SoundexTest, HandlesNonCodingCharacters) {
    EXPECT_EQ(generateSoundex("Tawfgjk"), "T12");
}

TEST(SoundexTest, HandlesPaddingAndTruncating) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}

TEST(SoundexTest, HandlesNonCodingStart) {
    EXPECT_EQ(generateSoundex("Euler"), "E460");
}

