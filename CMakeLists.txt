#cmake版本要求
cmake_minimum_required (VERSION 3.10)

#project name
project (leetcode)

#版本
set (LEETCODE_VERSION_MAJOR 1)
set (LEETCODE_VERSION_MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

#平台判定
IF (WIN32)
	MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
	MESSAGE(STATUS "Now is Apple systens.")
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")
ENDIF ()

#src目录
AUX_SOURCE_DIRECTORY (src DIR_SRCS)

# 检查系统是否支持 max 函数
INCLUDE (CheckFunctionExists)
check_function_exists (max HAVE_MAX)

#是否使用math
OPTION (USE_MYMATH "Use MathFunctions provided math implementation" ON)

IF (USE_MYMATH)
	INCLUDE_DIRECTORIES ("${PROJECT_SOURCE_DIR}/src/MathFunctions")
	ADD_SUBDIRECTORY (src/MathFunctions)
  	SET (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
ENDIF (USE_MYMATH)

#环境变量
SET (MAINSRC ${DIR_SRCS})

#生成可执行文件
ADD_EXECUTABLE (Demo ${MAINSRC})

#链接库文件
TARGET_LINK_LIBRARIES (Demo ${EXTRA_LIBS})

# 启用测试
ENABLE_TESTING ()
# 测试程序是否成功运行
ADD_TEST (test_run Demo 5 2)

# 定义一个宏，用来简化测试工作
MACRO (do_test arg1 arg2 result)
	ADD_TEST (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
	SET_TESTS_PROPERTIES (test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
ENDMACRO (do_test)

# 使用该宏进行一系列的数据测试
do_test (5 2 "is 5")
do_test (10 5 "is 10")
do_test (2 10 "is 10")