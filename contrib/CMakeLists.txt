set(BUILD_API_EXAMPLES OFF CACHE INTERNAL "" FORCE)
set(BUILD_API_TESTS OFF CACHE INTERNAL "" FORCE)
add_subdirectory("cpp-sc2")

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory("json")
