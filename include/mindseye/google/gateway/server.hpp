#pragma once

#include "mindseye/google/gateway/sse_bus.hpp"

namespace mindseye::google::gateway {

class Server {
public:
  Server();
  void run(int port);

  SSEBus& sse_bus();

private:
  SSEBus sse_;
};

} // namespace mindseye::google::gateway
