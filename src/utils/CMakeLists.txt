# Path definitions.
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add overall src library.
file(GLOB_RECURSE src_sources CONFIGURE_DEPENDS ${src_dir}/*.cpp)
add_library(utils ${src_sources})

target_include_directories(utils PUBLIC ${src_dir})
target_link_libraries(utils)
