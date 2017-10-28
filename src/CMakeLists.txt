set(SOURCES main.cpp MemoryController.cpp VideoController.cpp SoundController.cpp CPU.cpp)
set(HEADERS MemoryController.hpp VideoController.hpp SoundController.hpp CPU.hpp)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
