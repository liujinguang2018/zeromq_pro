
add_executable(hwserver hwserver.c)
install(TARGETS hwserver DESTINATION bin)


add_executable(hwclient hwclient.c)
install(TARGETS hwclient DESTINATION bin)

add_executable(version version.c)
install(TARGETS version DESTINATION bin)

add_executable(wuserver wuserver.c)
install(TARGETS wuserver DESTINATION bin)