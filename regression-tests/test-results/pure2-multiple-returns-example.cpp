
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 2 "/home/adesso/devel/cppfront/regression-tests/pure2-multiple-returns-example.cpp2"
struct f__ret {
    std::size_t age;
    std::string name;
    };
#line 3 "/home/adesso/devel/cppfront/regression-tests/pure2-multiple-returns-example.cpp2"
[[nodiscard]] auto f() -> f__ret;
#line 10 "/home/adesso/devel/cppfront/regression-tests/pure2-multiple-returns-example.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "/home/adesso/devel/cppfront/regression-tests/pure2-multiple-returns-example.cpp2"

[[nodiscard]] auto f() -> f__ret
      {
        cpp2::deferred_init<std::size_t> age;
        cpp2::deferred_init<std::string> name;
#line 4 "/home/adesso/devel/cppfront/regression-tests/pure2-multiple-returns-example.cpp2"


    age.construct(38);
    name.construct("Stefano");
    return  { std::move(age.value()), std::move(name.value()) }; }

[[nodiscard]] auto main() -> int{
    auto res {f()}; 
    std::cout << res.name << " is " << std::to_string(std::move(res).age) << " years old." << std::endl;
    return 0; 
}

