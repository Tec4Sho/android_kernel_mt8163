cmake_minimum_required(VERSION 3.10) # Specifies the minimum required CMake version

# ... other project settings ... #
project(MyProject VERSION 1.0 LANGUAGES CXX)

set_target_properties(MyProject PROPERTIES LINKER_LANGUAGE CXX)

set(LLVM_ENABLE_PROJECTS clang;clang-tools-extra)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 17) # Sets the C++ standard to C++17

set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensures the specified C++ standard is strictly enforced

set(CMAKE_CXX_EXTENSIONS ON) # Disables compiler-specific extensions for C++

add_executable(MyProject init/main.c) # Creates an executable target named "MyProject" from main.cpp

#add_executable(MyExecutable main.cpp my_source.cpp)

#target_link_libraries(MyExecutable PRIVATE MyLibrary)

#add_library(MyLibrary STATIC my_library_source.cpp)

#install(TARGETS MyExecutable DESTINATION bin)

#install(TARGETS MyLibrary DESTINATION lib)

#install(FILES my_library.h DESTINATION include)

find_program(CLANG_TIDY_EXE "clang-tidy")
  if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    # Configure clang-tidy to run with all checks and fix errors
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=*; -header-filter=.; -fix")
    # You can also specify specific checks instead of -checks=*
    # set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=modernize-loop-convert,readability-identifier-naming;-fix")
  else()
    message(WARNING "clang-tidy not found! Static analysis will be skipped.")
  endif()
