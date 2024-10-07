TARGET = gxde-timer
TEMPLATE = subdirs
SUBDIRS += \
        src/$${TARGET}.pro

# Update translation files
CONFIG(release, debug | release) {
    system(bash $${PWD}/translate_update.sh)
    system(bash $${PWD}/translate_generation.sh)
}

