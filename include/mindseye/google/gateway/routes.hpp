#pragma once

#include "mindseye/google/gateway/sse_bus.hpp"

namespace httplib { class Server; }

namespace mindseye::google::gateway {

void register_routes(httplib::Server& app, SSEBus& bus);

} // namespace mindseye::google::gateway
