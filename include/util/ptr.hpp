#ifndef UTIL_PTR_HPP
#define UTIL_PTR_HPP

#include <memory>

template<typename T, auto& DeleterFn>
struct deleter_from_fn
{
    void operator() (T* ptr) const
    {
        DeleterFn(const_cast<std::remove_const_t<T>*>(ptr));
    }
};

template<typename T, auto DeleterFn>
using c_unique_ptr = std::unique_ptr<T, deleter_from_fn<T, DeleterFn>>;

#endif
