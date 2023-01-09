cmake_minimum_required(VERSION 2.8)

project(chatapp)

set(SOURCE_EXE main.cpp Chat.h Chat.cpp User.h User.cpp "message.h")

add_executable(chat ${SOURCE_EXE})