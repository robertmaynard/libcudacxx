find_package(libcudacxx REQUIRED CONFIG
  NO_DEFAULT_PATH # Only check the explicit path in HINTS:
  HINTS "${CMAKE_CURRENT_LIST_DIR}/.."
)
