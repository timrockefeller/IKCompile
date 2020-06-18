SET(MODE "LIB")
set(TARGET_NAME "PL0CL")
IK_UnityArgs(STR_TARGET_SOURCES
    # sources, headfiles
    "${PROJECT_SOURCE_DIR}/include/Compiler/ASTNode.h"
    "${PROJECT_SOURCE_DIR}/include/Compiler/Pattern.h"
    "${PROJECT_SOURCE_DIR}/include/Compiler/Token.h"
    "${PROJECT_SOURCE_DIR}/include/PL0/ASTBuild.h"
    "${PROJECT_SOURCE_DIR}/include/PL0/PL0Grammar.h"
    "${PROJECT_SOURCE_DIR}/include/PL0/PL0Patterns.h"
    "ASTBuild.cpp"
    "PL0Pattern.cpp"
)
message(STATUS ${STR_TARGET_SOURCES})
IK_UnityArgs(STR_TARGET_LIBS
    # libs
)
IK_SetupProject(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} ${STR_TARGET_LIBS})
