set(SOURCES main.cpp memoryController.cpp videoController.cpp soundController.cpp lcdpalettes.cpp ldInstructions.cpp arithInstructions.cpp miscInstructions.cpp flowInstructions.cpp shiftInstructions.cpp CPU.cpp)
set(HEADERS memoryController.hpp videoController.hpp soundController.hpp CPU.hpp instruction.hpp ldInstructions.hpp arithInstructions.hpp miscInstructions.hpp flowInstructions.hpp shiftInstructions.hpp registerBank.hpp lcdpalettes.hpp types.hpp)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
