SET(MODE "LIB")
set(TARGET_NAME "Utils")
IK_UnityArgs(STR_TARGET_SOURCES
    # sources, headfiles
    "File.cpp"
    "ArgHandle.cpp"
    "View.cpp"
)
IK_UnityArgs(STR_TARGET_LIBS
    # libs
)
IK_SetupProject(${MODE} ${TARGET_NAME} ${STR_TARGET_SOURCES} ${STR_TARGET_LIBS})
