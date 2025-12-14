#include "mindseye/google/gateway/server.hpp"
#include <cstdlib>

int main() {
  int port = 8080;
  if (const char* p = std::getenv("PORT")) port = std::atoi(p);

  mindseye::google::gateway::Server server;
  server.run(port);
  return 0;
}
