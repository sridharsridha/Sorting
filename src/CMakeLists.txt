add_library(SortingLib INTERFACE)
add_library(SortingLib::SortingLib ALIAS SortingLib)

target_include_directories(SortingLib INTERFACE include/)

# Use project options and project warning defined in top level cmake file
target_link_libraries(SortingLib INTERFACE project_options project_warnings)
