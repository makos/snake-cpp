file(GLOB_RECURSE TESTSRC *.cpp)
set(SOURCEDIR ${CMAKE_HOME_DIRECTORY}/src)

add_executable(test ${TESTSRC} ${SOURCEDIR}/Player.cpp ${SOURCEDIR}/Point.cpp)
target_include_directories(test PUBLIC ${CMAKE_HOME_DIRECTORY}/include)