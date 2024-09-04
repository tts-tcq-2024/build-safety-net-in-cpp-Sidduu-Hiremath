#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    // Constructor
    Soundex();

    std::string generateSoundex(const std::string& name);

private:

    static const char soundexMap[26];

    char getSoundexCode(char c) const;

    std::string startSoundex(const std::string& name) const;

    void generateRemainingSoundex(std::string& soundex, const std::string& name) const;

    void processCurrentChar(std::string& soundex, char currentChar, char& prevCode, char& prevPrevChar) const;

    bool shouldAddCode(char prevPrevChar, char currentChar) const;

    void processCharacter(std::string& soundex, char code, char& prevCode) const;

    bool isValidSoundexCode(char code) const;

    bool isNewCode(char code, char prevCode) const;

    bool isSeparatedByHorW(char prevPrevChar) const;

    void padWithZeros(std::string& soundex) const;

    bool isVowel(char c) const;

    bool shouldContinueProcessing(size_t nameLength, size_t soundexLength) const;

    bool shouldAddCode(char currentCode, char prevCode, char prevPrevCode) const;

    bool isShortName(const std::string& name) const;
    bool canAddCode(char prevPrevCode, char currentCode) const ;
};

#endif // SOUNDEX_H
