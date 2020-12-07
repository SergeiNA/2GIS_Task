cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Использование adress sanitizer
get_property(USE_ASAN GLOBAL PROPERTY USE_ASAN)
# Использование Gtest
get_property(USE_TEST GLOBAL PROPERTY USE_TEST)


set (SRC_TEST_CRC           test_CRCWorker.cpp 
                            ${PROJECT_SOURCE_DIR}/src/WorkerCRC.cpp)

set (SRC_TEST_WCOUNT        test_WCountWorker.cpp 
                            ${PROJECT_SOURCE_DIR}/src/WorkerWCount.cpp)

set (SRC_TEST_SWCOUNT       test_SWCountWorker.cpp 
                            ${PROJECT_SOURCE_DIR}/src/WorkerStateWCount.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/EndScope.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/BeginScope.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/PEndMarks.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/Context.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/Miscellanea.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/NewWord.cpp
                            ${PROJECT_SOURCE_DIR}/src/StateWordCounter/Resembling.cpp
)

set (TESTS    
                test_CRCWorker
                                )

add_executable(
                test_CRCWorker
                ${SRC_TEST_CRC}
                                )

list(LENGTH TESTS len_TESTS_r)
math(EXPR len_TESTS "${len_TESTS_r} - 1")

foreach(i RANGE ${len_TESTS})
    list(GET TESTS ${i} test_name)
    list(GET TEST_SRC ${i} test_file)
    

    message("BUILD " ${test_file})
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
    if(USE_ASAN)
        message("[TESTS] LASAN IN USE")
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=leak")
    endif()
    message("DEBUG")
endif()

set_target_properties( ${TESTS} 
                    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "${CMP_OPTIONS}"
    LINK_FLAGS "${L_FLAGS}"
)

if(USE_TEST)

foreach(i RANGE ${len_TESTS})
    list(GET TESTS ${i} element)
    message(${element})

    target_link_libraries(
        ${element}
        Threads::Threads
        stdc++fs
        ${GTEST_LIBRARIES}
    )   
endforeach(i)

enable_testing()

foreach(i RANGE ${len_TESTS})
    list(GET TESTS ${i} element)
    add_test(${element} ${element})
endforeach(i)

endif()
