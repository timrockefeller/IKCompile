## For main extry file project
set(MODE "EXE")
set(TARGET_NAME "00_RegTest")
IK_UnityArgs(STR_TARGET_SOURCES
    # sources, headfiles
    "main.cpp"
)
IK_UnityArgs(STR_TARGET_LIBS
    # libs
)
IK_SetupProject(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} ${STR_TARGET_LIBS})
