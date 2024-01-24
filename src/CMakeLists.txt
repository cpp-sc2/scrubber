file(GLOB_RECURSE BOT_SOURCES "*.cpp" "*.h")

include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/contrib/cpp-sc2/include
    ${PROJECT_SOURCE_DIR}/contrib/cpp-sc2/contrib/protobuf/src
    ${PROJECT_BINARY_DIR}/contrib/cpp-sc2/generated
    "."
)

link_directories(${PROJECT_BINARY_DIR}/contrib/cpp-sc2/bin)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX-")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything \
        -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-weak-vtables \
        -Wno-switch-enum -Wno-covered-switch-default -Wno-padded \
        -Wno-documentation-pedantic -Wno-documentation-unknown-command"
    )
elseif (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_executable(Scrubber ${BOT_SOURCES})
target_link_libraries(Scrubber
    sc2api sc2lib sc2utils sc2protocol civetweb libprotobuf nlohmann_json::nlohmann_json
)

if (MINGW)
    target_link_libraries(Scrubber ssp)
endif()

if (APPLE)
    target_link_libraries(Scrubber "-framework Carbon")
endif ()

# Linux specific.
if (UNIX AND NOT APPLE)
    target_link_libraries(Scrubber pthread dl)
endif ()
