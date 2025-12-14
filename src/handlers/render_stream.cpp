#include "mindseye/google/gateway/handlers/render_stream.hpp"

namespace mindseye::google::gateway::handlers {

void handle_render_stream(const httplib::Request&, httplib::Response& res, SSEBus& bus) {
  res.set_header("Content-Type", "text/event-stream");
  res.set_header("Cache-Control", "no-cache");
  res.set_header("Connection", "keep-alive");

  // Simple snapshot stream (explicit, no background thread magic)
  auto snap = bus.snapshot();
  std::string out;
  out.reserve(4096);

  for (const auto& msg : snap) out += msg;

  res.set_content(out, "text/event-stream");
}

}
