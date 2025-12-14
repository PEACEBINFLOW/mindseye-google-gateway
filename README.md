# MindsEye Google Gateway

`mindseye-google-gateway` is the unified REST + SSE gateway for the MindsEye Google Fabric.

This repository is **transport**, not law.

It exposes HTTP endpoints for:
- ingesting events
- executing MindScript programs
- streaming render scenes
- viewing ledger state

---

## Purpose

MindsEye is a fabric.
Google is a surface.
This gateway is the **front door**.

The gateway:
- Validates and accepts inbound envelopes
- Runs MindScript deterministically via `mindscript-runtime`
- Dispatches Google ops via `mindscript-google-executor`
- Streams updates via SSE (render/ledger feeds)

---

## What lives here

- HTTP server + routing
- Auth middleware (explicit)
- Rate limiting stubs (explicit)
- SSE streaming bus
- Handlers that call runtime + executor

---

## What does NOT live here

- Protocol definitions (`mindseye-protocol`)
- Deterministic MindScript execution (`mindscript-runtime`)
- Google op implementations (`mindscript-google-executor`)
- Business logic / UI / Apps Script

If it defines meaning, it does not belong here.

---

## Architecture Position

Clients / Google triggers / Cloud events
│
▼
┌───────────────────────────────┐
│ mindseye-google-gateway │ ← THIS REPO
│ (REST + SSE front door) │
└───────────────┬───────────────┘
│
┌──────────▼───────────┐
│ mindscript-runtime │ (deterministic engine)
└──────────┬───────────┘
│
┌──────────▼───────────┐
│ mindscript-google- │ (google surface adapter)
│ executor │
└──────────────────────┘
│
Google Workspace / GCP

yaml
Copy code

---

## Submodules (Mandatory)

```text
external/
├─ mindseye-protocol
├─ mindscript-runtime
└─ mindscript-google-executor
Add them:

https://github.com/PEACEBINFLOW/mindseye-protocol/tree/main
https://github.com/PEACEBINFLOW/mindscript-runtime-c/tree/main
https://github.com/PEACEBINFLOW/mindscript-google-executor/tree/main



