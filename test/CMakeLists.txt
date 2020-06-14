# automatically enable catch2 to generate ctest targets
if(CONAN_CATCH2_ROOT_DEBUG)
  include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else()
  include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif()

# Add a file containing a set of constexpr tests
add_executable(sorting_tests sorting_tests.cpp)
target_link_libraries(
  sorting_tests PRIVATE project_options project_warnings CONAN_PKG::catch2
                        SortingLib::SortingLib)

catch_discover_tests(sorting_tests TEST_PREFIX "sorting." EXTRA_ARGS -s)
