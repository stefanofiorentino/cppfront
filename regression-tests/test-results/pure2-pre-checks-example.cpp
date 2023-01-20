// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-example.cpp2"
[[nodiscard]] auto main() -> int;
#line 7 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-example.cpp2"
auto fill(
    cpp2::out<std::vector<int>> x,
    cpp2::in<int> count,
    cpp2::in<int> value
    ) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-example.cpp2"
[[nodiscard]] auto main() -> int{
    cpp2::deferred_init<std::vector<int>> answers_to_everything;
    auto int_max {std::numeric_limits<int>::max()};
    fill(&    answers_to_everything, std::move(int_max), 42);
}

auto fill(
    cpp2::out<std::vector<int>> x,
    cpp2::in<int> count,
    cpp2::in<int> value
    ) -> void{
        x.construct(std::vector<int>(count, value));
}

