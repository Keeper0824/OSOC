#!/usr/bin/env bash

marco() {
  pwd > "${HOME}/.marco"
}

polo() {
  cd "$(cat "${HOME}/.marco")"
}
