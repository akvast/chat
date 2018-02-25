
#include <strstream>

#ifdef ANDROID

#define log2(x) (log(x) / log(2))

namespace std {

    template <typename T>
    string to_string(T value)
    {
        ostringstream os;
        os << value;
        return os.str();
    }

}

#end