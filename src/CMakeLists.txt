cmake_minimum_required(VERSION 3.9)
project(Test_task_2GIS VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS 
                              program_options 
                              filesystem 
                              REQUIRED)

get_property(USE_TSAN GLOBAL PROPERTY USE_TSAN)
get_property(USE_ASAN GLOBAL PROPERTY USE_ASAN)
get_property(USE_TEST GLOBAL PROPERTY USE_TEST)


# include_directories(${PROJECT_SOURCE_DIR}/src/include) # не работает ...
set (EXE_NAME   hash_count)

set (SRC_FILES 
				common.cpp
                AppOptions.cpp
                ProcessManager.cpp
                ProcessWCount.cpp
                ProcessCRC.cpp
				main.cpp
				)

add_executable(${EXE_NAME}  ${SRC_FILES})


set(CMP_OPTIONS "-pthread;-Wpedantic;-Wall;-Wextra")
set(L_FLAGS "")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions( ${EXE_NAME}  PUBLIC -DDEBUG)  # -D removed
    list(APPEND CMP_OPTIONS "-g")

    if(USE_TSAN)
        message("[SRC] LTASN IN USE")
        list(APPEND CMP_OPTIONS "-fsanitize=thread")
        list(APPEND L_FLAGS "-fsanitize=thread")
    endif()

    if(USE_ASAN)
        message("[SRC] LASAN IN USE")
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=leak")
    endif()

    message("debug")
endif()

set_target_properties(${EXE_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "${CMP_OPTIONS}"
    LINK_FLAGS "${L_FLAGS}"

    # LINK_FLAGS "-fsanitize=address"
    # LINK_FLAGS "-fsanitize=leak"
)

target_link_libraries(${EXE_NAME}
	${Boost_LIBRARIES}
    Threads::Threads
)


# include(CTest)
# enable_testing()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
