#!/bin/bash
# this file is used to auto-update .ts file.

cd $(dirname $0)

/usr/lib/qt6/bin/lupdate ./src/* -ts ./translations/*.ts -no-obsolete
