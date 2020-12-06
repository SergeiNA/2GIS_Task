cmake_minimum_required(VERSION 3.9)
project(Test_task_2GIS VERSION 1.0.0)

# Включение и выключение adress sanitizer
set_property(GLOBAL PROPERTY USE_ASAN 1)
# Включение и выключение тестов
set_property(GLOBAL PROPERTY USE_TEST 1)
get_property(USE_TEST GLOBAL PROPERTY USE_TEST)
# add_definitions(-DDEBUG_PRINT)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
if (USE_TEST)
  enable_testing()
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()


