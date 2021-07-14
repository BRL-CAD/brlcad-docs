#!/bin/bash
# Build the docs site with the lunr search enabled

export DOCSEARCH_ENABLED=true
export DOCSEARCH_ENGINE=lunr
export NODE_PATH="$(npm -g root)"

antora='antora --generator antora-site-generator-lunr'
$antora build.yml
$antora translations/build-es.yml
