#-------------
# Tests

foreach(name core ui utils)
    file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/${name}/*.cpp")
    add_executable(test_${name} ${TEST_SOURCES})
    target_include_directories(test_${name} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/fixtures
    )
    target_compile_definitions(test_${name} PRIVATE
        TEST_RESOURCES_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources"
    )
    target_link_libraries(test_${name} PRIVATE template_lib GTest::gtest_main)
    add_test(NAME test_${name} COMMAND $<TARGET_FILE:test_${name}>)
endforeach()

