#include <string>
#include <vector>
#include <cctype>
#include "../interfaces/ITokenizer.h"

class SpaceTokenizer: ITokenizer{
private:
    static bool isSpace(unsigned char c) { return std::isspace(c) != 0; }

    static void buffer_push(std::string_view slice, Buffer& out) {
        out.input.emplace_back(slice); // copies slice into a new std::string
    }
public:
    Buffer Tokenize(const TokenBuffer& tb) {
        Buffer out;
        const auto s = tb.input;
        size_t i = 0, n = s.size();

        while (i < n) {
            while (i < n && isSpace((unsigned char)s[i])) ++i;
            size_t begin = i;
            while (i < n && !isSpace((unsigned char)s[i])) ++i;
            size_t end = i;
            if (end > begin) buffer_push(s.substr(begin, end - begin), out);
        }
        return out;
    }
};