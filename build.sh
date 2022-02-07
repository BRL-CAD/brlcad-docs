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
        cp build.yml build-offline.yml
        sed -i build-offline.yml \
            -e "/^site:/,+2 s!url:.*!url: $destination/html/docs!" \
            -e "/^content:/,+1 s!edit_url:.*!edit_url: ~!" \
            -e "/^output:/,+1 s!dir:.*!dir: $destination/html!"
        rm -rf $destination/html/
        npx antora build-offline.yml
        rm build-offline.yml
        ;;
    *)
        usage
        ;;
esac
