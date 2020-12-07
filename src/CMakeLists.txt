cmake_minimum_required(VERSION 3.9)
project(Test_task_2GIS VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS 
                              program_options 
                              REQUIRED)

get_property(USE_ASAN GLOBAL PROPERTY USE_ASAN)

set (EXE_NAME   fileWorker)

set (SRC_FILES 
                StateWordCounter/EndScope.cpp
                StateWordCounter/BeginScope.cpp
                StateWordCounter/PEndMarks.cpp
				StateWordCounter/Context.cpp
				StateWordCounter/Miscellanea.cpp
				StateWordCounter/NewWord.cpp
				StateWordCounter/Resembling.cpp
                AppOptions.cpp
                WorkerManager.cpp
				WorkerWCount.cpp
				WorkerStateWCount.cpp
                WorkerCRC.cpp
				main.cpp
				)

add_executable(${EXE_NAME}  ${SRC_FILES})

target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMP_OPTIONS "-pthread;-Wpedantic;-Wall;-Wextra")
set(L_FLAGS "")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions( ${EXE_NAME}  PUBLIC -DDEBUG)
    list(APPEND CMP_OPTIONS "-g")

    if(USE_ASAN)
        message("[SRC] LASAN IN USE")
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=address")
        list(APPEND CMP_OPTIONS "-fsanitize=leak")
    endif()

    message("DEBUG")
endif()

set_target_properties(${EXE_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "${CMP_OPTIONS}"
    LINK_FLAGS "${L_FLAGS}"
)

target_link_libraries(${EXE_NAME}
	${Boost_LIBRARIES}
    Threads::Threads
    stdc++fs
)

