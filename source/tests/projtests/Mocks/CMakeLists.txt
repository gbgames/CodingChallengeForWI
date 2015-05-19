FILE (GLOB TEST_SOURCES *.cpp )
INCLUDE_DIRECTORIES (${gtest_SOURCE_DIR}/include 
					${gtest_SOURCE_DIR} 
					${gmock_SOURCE_DIR}/include 
					${PROJECT_SOURCE_DIR}/source/proj)	

ADD_LIBRARY (${GB_PROJECT_NAME}Mocks-lib ${TEST_SOURCES})

TARGET_LINK_LIBRARIES (${GB_PROJECT_NAME}Mocks-lib gtest gtest_main gmock) 
