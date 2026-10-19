cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for sheenbidi")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/home/mrgigmak/my_own_3d_sfml_project/build/_deps/sheenbidi-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/usr/bin/cmake]====] [====[-DSHEENBIDI_DIR=/home/mrgigmak/my_own_3d_sfml_project/build/_deps/sheenbidi-src]====] [====[-P]====] [====[/home/mrgigmak/my_own_3d_sfml_project/build/_deps/sfml-src/tools/sheenbidi/PatchSheenBidi.cmake]====]
)

endblock()
