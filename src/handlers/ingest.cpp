#include "mindseye/google/gateway/handlers/ingest.hpp"
#include "mindseye/google/gateway/auth_middleware.hpp"
#include "mindseye/google/gateway/rate_limit.hpp"

namespace mindseye::google::gateway::handlers {

void handle_ingest(const httplib::Request& req, httplib::Response& res, SSEBus& bus) {
  RequestContext ctx;
  const auto auth = req.get_header_value("Authorization");
  const auto principal = req.get_header_value("X-Principal");

  if (!AuthMiddleware::extract(auth, principal, ctx)) {
    res.status = 401;
    res.set_content("{\"error\":\"unauthorized\"}", "application/json");
    return;
  }

  if (!RateLimit::allow(ctx.principal, "/v1/ingest")) {
    res.status = 429;
    res.set_content("{\"error\":\"rate_limited\"}", "application/json");
    return;
  }

  // Ingest body as an event payload (opaque here).
  bus.publish("ingest", req.body);

  res.set_content("{\"ok\":true}", "application/json");
}

}
