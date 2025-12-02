add_compile_options(-Wno-unused-but-set-variable)
add_compile_options(-Wno-unused-variable)

add_executable(doris_rinex_iterator doris_rinex_iterator.cpp)
target_link_libraries(doris_rinex_iterator PRIVATE rnx ${PROJECT_DEPENDENCIES})
#add_test(NAME doris_rinex_iterator COMMAND doris_rinex_iterator
#)

add_executable(doris_rinex_iterator_data doris_rinex_iterator_data.cpp)
target_link_libraries(doris_rinex_iterator_data PRIVATE rnx ${PROJECT_DEPENDENCIES})
