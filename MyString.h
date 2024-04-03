#pragma once

class MyString
{
private:
    static int Length(const char* str)
    {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

public:
    static bool StartWith(std::string str, std::string prefix) {
        int strLen = Length(str.c_str());
        int prefixLen = Length(prefix.c_str());

        if (prefixLen > strLen) {
            return false;
        }

        for (int i = 0; i < prefixLen; ++i) {
            if (str[i] != prefix[i]) {
                return false;
            }
        }

        return true;
    }

    static bool EndWith(std::string str, std::string suffix) {
        int strLen = Length(str.c_str());
        int suffixLen = Length(suffix.c_str());

        if (suffixLen > strLen) {
            return false;
        }

        for (int i = 0; i < suffixLen; ++i) {
            if (str[strLen - suffixLen + i] != suffix[i]) {
                return false;
            }
        }

        return true;
    }

    static bool Contains(std::string str, std::string substring)
    {
        int strLen = Length(str.c_str());
        int subLen = Length(substring.c_str());

        for (int i = 0; i <= strLen - subLen; ++i) {
            bool match = true;
            for (int j = 0; j < subLen; ++j) {
                if (str[i + j] != substring[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }

        return false;
    }
    static bool Contains(std::string str, const std::vector<std::string>& substrings)
    {
        int strLen = Length(str.c_str());
        for (const std::string& substring : substrings)
        {
            int subLen = Length(substring.c_str());

            for (int i = 0; i <= strLen - subLen; ++i) {
                bool match = true;
                for (int j = 0; j < subLen; ++j) {
                    if (str[i + j] != substring[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }

    static std::string Remove(const std::string& str, const std::string& substr)
    {
        std::string result = str;
        size_t pos = result.find(substr);
        while (pos != std::string::npos)
        {
            result.erase(pos, substr.length());
            pos = result.find(substr, pos);
        }
        return result;
    }
    static std::string Remove(const std::string& str, const std::vector<std::string>& substrList)
    {
        std::string result = str;
        for (const std::string& substr : substrList)
            result = Remove(result, substr);
        return result;
    }

    static std::string Replace(const std::string& str, const std::string& oldStr, const std::string& newStr)
    {
        std::string result = str;
        size_t pos = result.find(oldStr);
        while (pos != std::string::npos)
        {
            result.replace(pos, oldStr.length(), newStr);
            pos = result.find(oldStr, pos + newStr.length());
        }
        return result;
    }
};
