cmake_minimum_required(VERSION 3.25.1...3.28.1)
project(khan_academy_math_study_notes VERSION 0.0.0.4)
set(CMAKE_MAKE_PROGRAM "ninja")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(VARIABLE_INCLUDE_standard ON)
set(VARIABLE_INLUCDE_experimental IGNORE)

add_executable(khan_academy_math_study_notes main.cpp)

if(VARIABLE_INCLUDE_standard)
    if(VARIABLE_INLUCDE_experimental)
        target_compile_definitions(khan_academy_math_study_notes PRIVATE
                "COMPILE_DEFINITION_INCLUDE_standard"
                "COMPILE_DEFINITIONS_INCLUDE_experimental"
        )
    endif()
    target_compile_definitions(khan_academy_math_study_notes PRIVATE
            "COMPILE_DEFINITION_INCLUDE_standard"
    )
endif()