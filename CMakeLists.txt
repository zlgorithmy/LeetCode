#cmake版本要求
cmake_minimum_required(VERSION 3.10)

#project name
project(leetcode)

#版本
set (LEETCODE_VERSION_MAJOR 1)
set (LEETCODE_VERSION_MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
)

#平台判定
IF (WIN32)
	MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systens.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")
ENDIF ()

#是否使用math
OPTION (USE_MYMATH "Use tutorial provided math implementation" ON)

IF (USE_MYMATH)
	INCLUDE_DIRECTORIES ("${PROJECT_SOURCE_DIR}/src/MathFunctions")
	ADD_SUBDIRECTORY (src/MathFunctions)
  	SET (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
ENDIF (USE_MYMATH)


#src目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#环境变量
SET(MAINSRC ${DIR_SRCS})

#生成可执行文件
ADD_EXECUTABLE(main ${MAINSRC})

#链接库文件
TARGET_LINK_LIBRARIES(main ${EXTRA_LIBS})