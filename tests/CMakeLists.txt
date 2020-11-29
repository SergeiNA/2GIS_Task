cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Использование thread sanitizer
get_property(USE_TSAN GLOBAL PROPERTY USE_TSAN)
# Использование adress sanitizer
get_property(USE_ASAN GLOBAL PROPERTY USE_ASAN)
# Использование Gtest
get_property(USE_TEST GLOBAL PROPERTY USE_TEST)


# include_directories(${PROJECT_SOURCE_DIR}/src/include)

set(TEST_SRC 
                test_foo.cpp
                            )

set (TESTS    
                test_foo
                            )


list(LENGTH TESTS len_TESTS_r)
math(EXPR len_TESTS "${len_TESTS_r} - 1")

foreach(i RANGE ${len_TESTS})
    list(GET TESTS ${i} test_name)
    list(GET TEST_SRC ${i} test_file)
    

    add_executable(
        ${test_name}
        ${test_file}
        ${PROJECT_SOURCE_DIR}/src/common.cpp
    )
    target_include_directories(
        ${test_name}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src/include
    )

endforeach(i)


set(CMP_OPTIONS "-pthread;-Wpedantic;-Wall;-Wextra")
set(L_FLAGS "")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    list(APPEND CMP_OPTIONS "-g")
    if(USE_TSAN)
        message("[TESTS] LTASN IN USE")
        list(APPEND CMP_OPTIONS "-fsanitize=thread")
        list(APPEND L_FLAGS "-fsanitize=thread")
    endif()
    if(USE_ASAN)
        message("[TESTS] LASAN IN USE")
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=leak")
    endif()
    message("debug")
endif()

set_target_properties( ${TESTS} 
                    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "${CMP_OPTIONS}"
    LINK_FLAGS "${L_FLAGS}"

    # LINK_FLAGS "-fsanitize=address"
    # LINK_FLAGS "-fsanitize=leak"
)




if(USE_TEST)

foreach(i RANGE ${len_TESTS})
    list(GET TESTS ${i} element)
    message(${element})

    target_link_libraries(
        ${element}
        Threads::Threads
        ${GTEST_LIBRARIES}
    )   
endforeach(i)

enable_testing()

foreach(i RANGE ${len_TESTS})
    list(GET TESTS ${i} element)
    add_test(${element} ${element})
endforeach(i)

endif()
