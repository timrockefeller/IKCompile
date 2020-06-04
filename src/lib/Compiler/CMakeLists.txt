SET(MODE "LIB")
set(TARGET_NAME "IKC")
IK_UnityArgs(STR_TARGET_SOURCES
    # sources, headfiles
    "${PROJECT_SOURCE_DIR}/include/Compiler/Grammar.h"
    "Grammar.cpp"
)
IK_UnityArgs(STR_TARGET_LIBS
    # libs
)
IK_SetupProject(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} ${STR_TARGET_LIBS})
