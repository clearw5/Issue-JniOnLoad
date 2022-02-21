
add_library(foo SHARED foo.cc)

target_link_libraries(foo log bar)

add_library(bar SHARED bar.cc)
target_link_libraries(bar log)

