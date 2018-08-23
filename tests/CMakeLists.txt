file(GLOB_RECURSE TESTSRC *.cpp)
set(SOURCEDIR ${CMAKE_HOME_DIRECTORY}/src)

add_executable(test ${TESTSRC} ${SOURCEDIR}/Player.cpp ${SOURCEDIR}/Point.cpp ${SOURCEDIR}/Menu.cpp ${SOURCEDIR}/MenuItem.cpp)
target_include_directories(test PUBLIC ${CMAKE_HOME_DIRECTORY}/include)