cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project (DialogHostTest)

find_package(Qt5 COMPONENTS
	gui	
	widgets
	core
REQUIRED)

add_executable (DialogHostTest DialogHost.h ExampleHost.h ExampleDialog.h main.cpp)

target_link_libraries(${PROJECT_NAME}
	Qt5::Gui
	Qt5::Widgets
)

set(QT_DLL_BIN ${Qt5Core_DIR}/../../../bin)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
	COMMENT "Copying Qt Binaries" VERBATIM
)
