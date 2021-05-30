#!/bin/bash

usage() {
    echo "
Usage: $0 <file.xml>

Wrapper to dockbookrx, to facilitate calling it from any location.
"
    exit 1
}

xml_file=$1
[[ -n $xml_file ]] || usage
xml_file=$(realpath $xml_file)

cd $(dirname $0)/docbookrx/
bundle exec docbookrx $xml_file
