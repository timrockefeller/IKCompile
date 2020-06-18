cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME "IKCL_PL0")
set(PROJECT_VERSION 0.1.0)


project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(IKInit)
IK_InitProject("IKCL_PL0")

message(STATUS "[Project] ${PROJECT_NAME} ${PROJECT_VERSION}")

include_directories (
    ${PROJECT_SOURCE_DIR}/include
    # ${CMAKE_BINARY_DIR}/config
    # $ENV{XXX_INCLUDE_PATH}
    # ...
)

link_directories (
    ${PROJECT_SOURCE_DIR}/lib
    # ${PROJECT_SOURCE_DIR}/lib/Gen
    # $ENV{XXX_LIB_PATH}
    # ...
)

IK_AddSubDirsRec("src")
