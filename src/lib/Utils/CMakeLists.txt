SET(MODE "LIB")
set(TARGET_NAME "Utils")
IK_UnityArgs(STR_TARGET_SOURCES
    # sources, headfiles
    "${PROJECT_SOURCE_DIR}/include/Utils/File.h"
    "File.cpp"
)
IK_UnityArgs(STR_TARGET_LIBS
    # libs
)
IK_SetupProject(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} ${STR_TARGET_LIBS})
