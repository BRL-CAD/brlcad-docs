#!/bin/bash
# Watch for modifications and rebuild the dev docs automatically.
# Depends on inotify-tools (apt install inotify-tools)

inotifywait -qmr -e modify --exclude '\.?#.*' docs/ \
  | while read event; do
      echo $(date +'%F %T') $event
      antora build-dev.yml
    done
