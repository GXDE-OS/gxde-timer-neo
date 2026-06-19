#!/bin/bash
# this file is used to auto-generate .qm file from .ts file.

cd $(dirname $0)

/usr/lib/qt6/bin/lrelease translations/gxde-timer_zh_CN.ts -qm translations/gxde-timer_zh_CN.qm
