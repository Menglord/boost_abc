aux_source_directory(. PROGRAM_OPTIONS_SRCS)
add_executable(program_options ${PROGRAM_OPTIONS_SRCS})
target_link_libraries(program_options ${Boost_LIBRARIES})
install(TARGETS program_options DESTINATION ${BINARY_DIR})