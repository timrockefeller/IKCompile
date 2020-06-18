## For main extry file project
set(MODE "EXE")
set(TARGET_NAME "default_case")
IK_UnityArgs(STR_TARGET_SOURCES
    # sources, headfiles
    "${PROJECT_SOURCE_DIR}/include/PL0/ASTBuild.h"
    "main.cpp"
)
IK_UnityArgs(STR_TARGET_LIBS
    # libs
    "PL0CL"
    "Utils"
)
IK_SetupProject(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} "PL0CL Utils")
