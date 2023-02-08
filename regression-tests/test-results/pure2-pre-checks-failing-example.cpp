
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 1 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-failing-example.cpp2"
[[nodiscard]] auto main() -> int;
#line 11 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-failing-example.cpp2"
auto fill(
    cpp2::out<std::vector<int>> x, 
    cpp2::in<int> count, 
    cpp2::in<int> value
    ) -> void;
#line 19 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-failing-example.cpp2"
auto handler(cpp2::in<char const*> msg) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "/home/adesso/devel/cppfront/regression-tests/pure2-pre-checks-failing-example.cpp2"
[[nodiscard]] auto main() -> int{
    CPP2_UFCS(set_handler, cpp2::Bounds, &handler);

    auto answers_to_everything {std::vector<int>()}; 
    auto int_max {std::numeric_limits<int>::max()}; 
    fill(&    answers_to_everything, 42, std::move(int_max));

    std::cout << cpp2::assert_in_bounds(std::move(answers_to_everything), 42) << "\n";
}

auto fill(
    cpp2::out<std::vector<int>> x, 
    cpp2::in<int> count, 
    cpp2::in<int> value
    ) -> void{
        x.construct(std::vector<int>(count, value));
}

auto handler(cpp2::in<char const*> msg) -> void{
    std::cerr << "Error detected: " << msg << "\n";
    std::_Exit(1);
}

