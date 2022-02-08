#!/bin/bash
# Build the docs HTML site.

usage() {
    cat <<EOF
Usage:
 - $0 online
 - $0 offline [destination]

   'destination' should be an absolute path.
   Default is the current directory.

EOF
    exit 1
}

destination=${2:-$(pwd)}
cd $(dirname $0)


case $1 in
    online)
        npx antora build.yml
        ;;
    offline)
        rm -rf $destination/html/
        npx antora build.yml \
	    --url $destination/html/docs \
	    --to-dir $destination/html
        ;;
    *)
        usage
        ;;
esac
