#!/usr/bin/env bash
set -e
cd "$(dirname "$0")/.."
rexglue migrate --app_root .
