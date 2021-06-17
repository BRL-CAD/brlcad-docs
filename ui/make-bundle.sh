#!/bin/bash -x

cd $(dirname $0)

# get antora-ui-default
git clone https://gitlab.com/antora/antora-ui-default ui-default

# apply customizations
cp -a src/css/custom.css ui-default/src/css/
echo '@import "custom.css";' >> ui-default/src/css/site.css

# build the ui bundle
cd ui-default/
npm install
npm install --global gulp-cli
gulp bundle
cd ..

# move the bundle to ui/
if [[ -f ui-default/build/ui-bundle.zip ]]; then
  rm -f ui-bundle.zip
  mv ui-default/build/ui-bundle.zip .
fi

# cleanup
rm -rf ui-default/
