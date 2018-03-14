cmake_minimum_required(VERSION 3.10)

project(zeromq_pro)


include_directories("include")

link_directories("lib")

link_libraries(libzmq-mt-gd-4_2_3)

add_subdirectory(src)

