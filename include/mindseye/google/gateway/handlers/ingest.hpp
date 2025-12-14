#pragma once
#include "mindseye/google/gateway/sse_bus.hpp"
#include "httplib.h"

namespace mindseye::google::gateway::handlers {

void handle_ingest(const httplib::Request& req, httplib::Response& res, SSEBus& bus);

}
