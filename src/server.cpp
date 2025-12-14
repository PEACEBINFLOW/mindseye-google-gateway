#include "mindseye/google/gateway/server.hpp"
#include "mindseye/google/gateway/routes.hpp"

#include "httplib.h"

#include <iostream>

namespace mindseye::google::gateway {

Server::Server() = default;

SSEBus& Server::sse_bus() { return sse_; }

void Server::run(int port) {
  httplib::Server app;
  register_routes(app, sse_);

  std::cout << "[mindseye-google-gateway] listening on :" << port << "\n";
  app.listen("0.0.0.0", port);
}

} // namespace mindseye::google::gateway
