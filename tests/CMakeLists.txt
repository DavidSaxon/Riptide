# set default build directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux_x86/tests)

# recurse
#add_subdirectory(unit)
add_subdirectory(functional/_buildsys)
#add_subdirectory(performance)
