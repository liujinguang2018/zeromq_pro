

#include_directories("include")

#link_directories("lib")

add_executable(hwserver hwserver.cpp)
install(TARGETS hwserver DESTINATION bin)


add_executable(hwclient hwclient.cpp)
install(TARGETS hwclient DESTINATION bin)