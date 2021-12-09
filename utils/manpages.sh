#!/bin/bash
### Generate man pages.

cd $(dirname $0)
cd ..

man_page_docs=docs/modules/man/pages
rm -rf manpages
mkdir -p manpages/{1,3,5,n}

asciidoctor -b manpage $man_page_docs/1/*.adoc
mv $man_page_docs/1/*.1 manpages/1/

asciidoctor -b manpage $man_page_docs/3/*.adoc
mv $man_page_docs/3/*.3 manpages/3/

asciidoctor -b manpage $man_page_docs/5/*.adoc
mv $man_page_docs/5/*.5 manpages/5/

asciidoctor -b manpage $man_page_docs/n/*.adoc
mv $man_page_docs/n/*.nged manpages/n/
