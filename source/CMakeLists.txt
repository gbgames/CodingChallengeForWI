ADD_SUBDIRECTORY (proj)
ADD_SUBDIRECTORY (tests)

INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/source/proj) 
ADD_EXECUTABLE (${GB_PROJECT_NAME}-bin main)
TARGET_LINK_LIBRARIES (${GB_PROJECT_NAME}-bin ${GB_PROJECT_NAME}-lib) 
INSTALL(TARGETS ${GB_PROJECT_NAME}-bin RUNTIME DESTINATION .)
