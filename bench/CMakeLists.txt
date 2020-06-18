# automatically enable catch2 to generate ctest targets
if(CONAN_CATCH2_ROOT_DEBUG)
  include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else()
  include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif()

add_executable(benchmark_catch benchmark_catch.cpp benchmark_catch.hpp)
target_link_libraries(
  benchmark_catch PRIVATE project_options project_warnings CONAN_PKG::catch2
                          SortingLib::SortingLib)

add_executable(benchmark_googlebench benchmark_googlebench.cpp benchmark_googlebench.hpp)
target_link_libraries(
  benchmark_googlebench PRIVATE project_options project_warnings CONAN_PKG::benchmark
                          SortingLib::SortingLib)
