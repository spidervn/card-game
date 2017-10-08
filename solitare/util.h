
#ifndef _SOLITARE_UTIL_H_
#define _SOLITARE_UTIL_H_

template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

#endif
