/**
    Interface for structures that can be folded.
*/
#pragma once

#include "boolean.h"
#include "utility.h"

template <typename f, typename z, typename s>
struct Foldable {
    using type = call<f, z, s>;
};

template <typename f, typename z, typename s>
using fold = typename Foldable<f, z, s>::type;


/**
*/
template <typename f, typename s>
struct Any {
    struct xx {
        template <typename p, typename c>
        using apply = logical_or<p::value, Thunk<call, f, c>>;
    };

    using type = fold<xx, std::false_type, s>;
};

template <typename f, typename s>
using any = typename Any<f, s>::type;
