cmake_minimum_required(VERSION 3.20.1)
project(libcudacxxTestExport CXX)

message(STATUS "libcudacxx_DIR=${libcudacxx_DIR}")
find_package(libcudacxx REQUIRED)

add_executable(version_check version_check.cxx)
target_link_libraries(version_check PRIVATE libcudacxx::libcudacxx)
enable_testing()
add_test(NAME version_check COMMAND "$<TARGET_FILE:version_check>")
set_property(TEST version_check PROPERTY
  PASS_REGULAR_EXPRESSION
  "${libcudacxx_VERSION_MAJOR}\.${libcudacxx_VERSION_MINOR}\.${libcudacxx_VERSION_PATCH}"
)
