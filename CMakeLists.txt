cmake_minimum_required(VERSION 3.20)
project(mindseye_google_gateway LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ---- HTTP server: cpp-httplib (header-only) ----
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.16.3
)
FetchContent_MakeAvailable(httplib)

# ---- Submodules ----
add_subdirectory(external/mindscript-runtime)
add_subdirectory(external/mindscript-google-executor)

add_executable(mindseye_google_gateway
  src/main.cpp
  src/server.cpp
  src/routes.cpp
  src/auth_middleware.cpp
  src/rate_limit.cpp
  src/sse_bus.cpp
  src/handlers/ingest.cpp
  src/handlers/mindscript_run.cpp
  src/handlers/render_stream.cpp
  src/handlers/ledger_view.cpp
)

target_include_directories(mindseye_google_gateway
  PUBLIC
    include
)

target_link_libraries(mindseye_google_gateway
  PUBLIC
    mindscript_runtime
    mindscript_google_executor
)

# cpp-httplib include
target_include_directories(mindseye_google_gateway
  PRIVATE
    ${httplib_SOURCE_DIR}
)

if (MSVC)
  target_compile_options(mindseye_google_gateway PRIVATE /W4)
else()
  target_compile_options(mindseye_google_gateway PRIVATE -Wall -Wextra -Wpedantic)
endif()
