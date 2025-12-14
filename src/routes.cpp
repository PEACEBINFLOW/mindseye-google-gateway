#include "mindseye/google/gateway/routes.hpp"
#include "mindseye/google/gateway/handlers/ingest.hpp"
#include "mindseye/google/gateway/handlers/mindscript_run.hpp"
#include "mindseye/google/gateway/handlers/render_stream.hpp"
#include "mindseye/google/gateway/handlers/ledger_view.hpp"

#include "httplib.h"

namespace mindseye::google::gateway {

void register_routes(httplib::Server& app, SSEBus& bus) {
  app.Get("/healthz", [](const httplib::Request&, httplib::Response& res) {
    res.set_content("{\"ok\":true}", "application/json");
  });

  app.Post("/v1/ingest", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::handle_ingest(req, res, bus);
  });

  app.Post("/v1/mindscript/run", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::handle_mindscript_run(req, res, bus);
  });

  app.Get("/v1/render/stream", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::handle_render_stream(req, res, bus);
  });

  app.Get("/v1/ledger/view", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::handle_ledger_view(req, res);
  });
}

} // namespace mindseye::google::gateway
