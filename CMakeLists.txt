cmake_minimum_required(VERSION 3.5.0)
project(StuManagement)

include(CTest)
enable_testing()



find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})



add_executable(main source/main.c source/stu_file.c source/stu_service.c source/show_ui.c)
target_link_libraries(main sqlite3)
target_link_libraries(main ${GTK3_LIBRARIES})
target_include_directories(main PRIVATE header)





