#include "mindseye/google/gateway/handlers/mindscript_run.hpp"
#include "mindseye/google/gateway/auth_middleware.hpp"
#include "mindseye/google/gateway/rate_limit.hpp"

#include "mindscript/google/executor.hpp"

namespace mindseye::google::gateway::handlers {

void handle_mindscript_run(const httplib::Request& req, httplib::Response& res, SSEBus& bus) {
  RequestContext ctx;
  const auto auth = req.get_header_value("Authorization");
  const auto principal = req.get_header_value("X-Principal");

  if (!AuthMiddleware::extract(auth, principal, ctx)) {
    res.status = 401;
    res.set_content("{\"error\":\"unauthorized\"}", "application/json");
    return;
  }

  if (!RateLimit::allow(ctx.principal, "/v1/mindscript/run")) {
    res.status = 429;
    res.set_content("{\"error\":\"rate_limited\"}", "application/json");
    return;
  }

  // Body is expected to be an envelope/program payload.
  // We keep it explicit: gateway does not guess formats.
  mindscript::google::Executor exec;

  // Execute program (implementation is inside mindscript-google-executor)
  exec.execute_program(req.body);

  // Broadcast that a program ran (opaque event for now).
  bus.publish("mindscript.run", "{\"principal\":\"" + ctx.principal + "\"}");

  res.set_content("{\"ok\":true}", "application/json");
}

}
